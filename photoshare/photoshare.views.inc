<?php

/**
 * @file
 *   Implementations for changing views
 */

/**
 * Implemets hook_views_data()
 *
 * Function for describing tables to views 
 *
 */
function photoshare_views_data() {
  $data['ps_spam_images']['table']['group'] = t('Spam reports');
  $data['ps_spam_images']['table']['base'] = array(
    'field' => 'id', // This is the identifier field for the view. 
    'title' => t('Spam reports'), 
    //'help' => t(''),
    'weight' => -10,
  );
  $data['ps_spam_images']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid', 
      'field' => 'nid',
    ),
  );
  $data['ps_spam_images']['nid'] = array(
    'title' => t('nid'), 
    'help' => t('to relate with spam reports.'),
    'relationship' => array(
      'base' => 'node', // The name of the table to join with. 
      'base field' => 'nid', // The name of the field on the joined table.
      // 'field' => 'nid' -- see hook_views_data_alter(); not needed here. 
      'handler' => 'views_handler_relationship', 
      'label' => t('Default label for the relationship'), 
      'title' => t('Title shown when adding the relationship'), 
      'help' => t('More information on this relationship'),
    ),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );
  return $data;
}
