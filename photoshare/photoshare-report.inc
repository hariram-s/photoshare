<?php

/**
 * @file
 *  Spam page implementation.
 */

/**
 * Function to get the report spam form.
 *
 * @param integer $nid.
 *
 * @return $form.
 */
function _photoshare_report_spam($nid) {
  // To get the login user details.
  global $user;
  $uid = $user->uid;
  $node = node_load($nid);
  $current_uid = $node->uid;
  if ($uid == $current_uid) {
    drupal_access_denied();
  }
  // To check whether the user logged in or not.
  // To display the email field.
  if (!$uid) {
    $email_reqd = 1;
  }
  else {
    $email_reqd = 0;
  }
  $form = drupal_get_form('_photoshare_report_spam_form', $email_reqd, $nid);

  return $form;
}

/**
 * To display the report spam form.
 *
 * @param array $form
 * @param array $form_state
 * @param integer $email_reqd
 *
 * @return  $form
 */
function _photoshare_report_spam_form($form, &$form_state, $email_reqd = "", $nid) {
  // Displays only if the email is required.
  if ($email_reqd) {
    $form['email'] = array(
      '#title' => t('Email'),
      '#type' => 'textfield',
      '#required' => TRUE,
      '#size' => 20,
      '#default_value' => '',
    );
  }

  $form['comment'] = array(
    '#title' => t('Enter the comment'),
    '#type' => 'textarea',
    '#required' => TRUE,
    '#size' => 20,
    '#default_value' => '',
  );

  $form['nid'] = array(
    '#type' => 'hidden',
    '#default_value' => $nid,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit Report',
  );

  return $form;
}

/**
 * To custom validation.
 *
 * @param  array $form
 * @param  array $form_state
 */
function _photoshare_report_spam_form_validate($form, &$form_state) {
  $mail = isset($form_state['values']['email']) ? $form_state['values']['email'] : NULL;
  if ($mail) {
    // inbuilt function to check the email valid or not.
    if (!valid_email_address($mail)) {
      form_set_error('email', t('The email address appears to be invalid.'));
    }
  }
}

/**
 * Defines submit handler.
 *
 * @param array $form
 * @param array $form_state
 */
function _photoshare_report_spam_form_submit($form, &$form_state) {
  global $user;
  $mail = isset($form_state['values']['email']) ? $form_state['values']['email'] : $user->mail;
  $uid = $user->uid;
  $nid = $form_state['values']['nid'];
  $sql = "";
  $sql .= "SELECT nid FROM {ps_spam_images} ";
  $sql .= "WHERE nid = :nid ";
  $result = db_query($sql, array(':nid' => $nid));
  $record = $result->fetchAssoc();
  if (empty($record)) { 
    $spam_entry = array(
      'nid' => $nid,
      'status' => 1,
    );
  $result = db_insert('ps_spam_images')
    ->fields($spam_entry)
    ->execute();
  }
  else {
    $query1 = db_update('ps_spam_images')
      ->condition('nid', $nid, '=')
      ->fields(array('status' => 1))
      ->execute();
  }
  $entry = array(
    'user_id' => isset($uid) ? $uid : 0,
    'nid' => $nid,
    'email' => $mail,
    'comment' => $form_state['values']['comment'],
  );
  $result = db_insert('ps_spam_reports')
    ->fields($entry)
    ->execute();
  drupal_set_message(t('Report has been send successfully'));
}
