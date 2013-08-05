<?php

/**
 * @file
 *  Spam management page
 */

/**
 * function to display the photoshare spam management page.
 */
function _photoshare_spam_management($nid) {
  $spam = array();
  $spam_msgs = _photoshare_get_spam($nid);
  if ($spam_msgs) {
    $output['reports'] = array(
      "#theme" => 'photoshare_spam_reports',
      "#spams" => $spam_msgs['spams'],
      "#attached" => array(
      'css' => array(
        drupal_get_path('module', 'photoshare') . '/css/photoshare-spam-reports.css')
    ),
    );
    
    $output['form'] = drupal_get_form("photoshare_spam_management_form", $nid);
    return $output;
  }
  else {
    $msg = "There is no spams for this image";
    return $msg;
  }
} 

/**
 * A custom theme function.
 *
 */
function theme_photoshare_spam_reports($variables) {
  $spams = $variables['spams'];
  $output = '<div class="photoshare-spam-reports">';
  foreach ($spams as $spam) {
    $output .= "<div class=comments> {$spam['comments']} </div>";
    $output .= "<div class=emails> {$spam['emails']} </div>";
  }
  $output .= "</div>";
  return $output;
}

/**
 * Function to get the spam messages.
 */
function _photoshare_get_spam($nid) {
  $sql = "";
  $sql .= "SELECT nid FROM {ps_spam_images} ";
  $sql .= "WHERE nid = :nid AND status >= :status";
  $result = db_query($sql, array(':nid' => $nid, ':status' => 1));
  $record = $result->fetchAssoc();
  $output = array();
  if (!empty($record)) {
    $sql = "";
    $sql .= "SELECT * FROM {ps_spam_reports} ";
    $sql .= "WHERE nid = :nid AND flag = :flag";
    $result = db_query($sql, array(':nid' => $nid, ':flag' => 1));
    foreach ($result as $record) {
      $spam['comments'] = $record->comment;
      $spam['emails'] = $record->email;
      $output['spams'][] = $spam;
    } 
  }
  return $output;
}

/**
 * Function to display the spam management form.
 */
function photoshare_spam_management_form($form, &$form_state, $nid) {
  $form['nid'] = array(
    '#type' => 'hidden',
    '#default_value' => $nid,
  );
  $form['accept'] = array(
    '#type' => 'submit',
    '#value' => 'Accept spam',
    '#submit' => array('_photoshare_spam_management_accept_submit'),
  );
  $form['reject'] = array(
    '#type' => 'submit',
    '#value' => 'Reject spam',
    '#submit' => array('_photoshare_spam_management_reject_submit'),
  );
  
  return $form;
}

/**
 * Defines submit handler.
 *
 * @param array $form
 * @param array $form_state
 */
function _photoshare_spam_management_accept_submit($form, &$form_state) {
  $nid = $form_state['values']['nid'];
  $accept = $form_state['values']['accept'];
  $query1 = db_update('ps_spam_images')
    ->condition('nid', $nid, '=');
  if (isset($accept)) {
    $query1 = $query1->fields(array(
      'status' => 2,
    ));
    $query1 = $query1->execute();    
  }
  // Ask the trigger module for all actions enqueued for the 'admin_accecpt_spam' trigger.
  $aids = trigger_get_assigned_actions('photoshare_admin_accepted_spam');
  // prepare a basic context, indicating group and "hook", and call all the
  // actions with this context as arguments.
  $context = array(
    'group' => 'photoshare',
    'hook' => 'photoshare_admin_accepted_spam'
  );
  $node = node_load($nid);
  actions_do(array_keys($aids), (object) $node, $context); 
}

/**
 * Defines submit handler.
 *
 * @param array $form
 * @param array $form_state
 */
function _photoshare_spam_management_reject_submit($form, &$form_state) {
  $nid = $form_state['values']['nid'];
  $reject = $form_state['values']['reject'];
  $query1 = db_update('ps_spam_images')
    ->condition('nid', $nid, '=');
  if (isset($reject)) {
    $query1 = $query1->fields(array(
      'status' => 0,
    ));
    $query1 = $query1->execute();
    $query2 = db_update('ps_spam_reports')
    ->fields(array(
      'flag' => 0,
    ))
    ->condition('nid', $nid, '=')
    ->execute();  
  }
}
