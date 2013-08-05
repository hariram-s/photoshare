<?php

/**
 * @file.
 * Includes for photostream pages.
 */

/**
 * The function displays the photostream page for the images added by each user.
 * To displays the photostream page for the images in the specified album.
 * To display the photostream page for the images in each category.
 *
 * @param string username
 * @param string album_id
 * @param string category_name
 *
 * @return the array with the items to be displayed
 */
function photoshare_get_photostream($username = NULL, $album_id = NULL, $category_name = NULL) {
  $items = array();
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'image')
    ->propertyCondition('status', 1)
    ->propertyOrderBy('created', 'DESC');

  if (isset($album_id) && isset($username)) {
    $result = db_query("SELECT uid FROM {users} u WHERE name=:uname",
    array(':uname' => $username)
  );
    $user = array();
    $user = $result->fetchAssoc();
    $query = $query->propertyCondition('uid', $user['uid']);
    $query = $query->fieldCondition('field_ps_album', 'target_id', $album_id);
  }
  elseif (isset($username)) {
    $result = db_query("SELECT uid FROM {users} u WHERE name=:uname",
      array(':uname' => $username)
    );
    $user = array();
    $user = $result->fetchAssoc();
    $query = $query->propertyCondition('uid', $user['uid']);
  }
  elseif (isset($category_name)) {
    $result = db_query("SELECT tid FROM {taxonomy_term_data} t WHERE name=:cname",
      array(':cname' => $category_name)
    );
    $category = array();
    $category = $result->fetchAssoc();
    $query = $query->fieldCondition('field_ps_category', 'tid', $category['tid']);
  }
  $result = $query->execute();
  if (isset($result['node'])) {
    $nids = array_keys($result['node']);
    $nodes = node_load_multiple($nids);
  }
  if (empty($nodes)) {
    $msg = "No images added yet";
    return $msg;
  }
  else {  
    foreach ($nodes as $node) {
      $items[] = array(
        '#node' => $node,
        '#theme' => 'photostream_item',
      );
    }
    $output = array(
      '#items' => $items,
      '#theme' => 'photostream',
      '#attached' => array('css' => array(drupal_get_path('module', 'photoshare') . '/css/photostream.css')),
    );
    return $output;
  }
}


