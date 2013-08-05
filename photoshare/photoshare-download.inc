<?php

/**
 * @file
 *  Download page implementation.
 */
 
/**
 * Function to get the report spam form.
 *
 * @param integer $nid.
 *
 * @return $form.
 */
function _photoshare_download($nid, $style) {
  $image_info = image_get_info('public://photoshare/private/' . $nid . '_' . $style);
  $query = "SELECT field_ps_image_fid FROM {field_data_field_ps_image} WHERE entity_id=:entity_id";
  $result = db_query($query, array(':entity_id' => $nid));
  $file_id = $result->fetchAssoc();
  $fid = $file_id['field_ps_image_fid'];
  global $user;
  $uid = $user->uid;
  $time = time();
  if (!$image_info) {
    $file = file_load($fid);
    $file_name = $file->filename;
    $file_item = explode(".", $file_name);
    $extension = $file_item[1];
    $destination = "public://photoshare/private/" . $nid . "_" . $style . '.' . $extension;
    $source = $file->uri;
    $photoshare_image_style = 'ps-' . $style;
    $image_style = image_style_load($photoshare_image_style);
    $create_image_style = image_style_create_derivative($image_style, $source, $destination);
  }
  global $user;
  $user = user_load($user->uid);
  $roles = $user->roles;
  $node = node_load($nid);
  $author = ($node->uid == $user->uid);
  $premium_user = in_array('premium_user', $roles);
  $administrator = in_array('administrator', $roles);
  if ($premium_user || $administrator || $author) {
    $image_extension = !empty($image_info)?$image['extension']:$extension; 
    $value = 'image/' . $image_extension; 
    header("Content-type: " . $value);
    header("Cache-Control: no-store, no-cache, must-revalidate");
    header("Cache-Control: post-check=0, pre-check=0", FALSE);
    header("Pragma: no-cache");
    $file_name = drupal_realpath('public://photoshare/private/' . $nid . '_' . $style . '.' . $image_extension);
    header("Content-Disposition: attachment; filename=" . $file_name );
    $size= filesize($file_name);
    header("Content-Length: $size bytes");
    readfile($file_name);
    $download_info = array(
      'user_id' => $uid,
      'fid' => $fid,
      'download_time' => $time,
      'download_size' => $style,
    );
    $result = db_insert('ps_image_downloads')
      ->fields($download_info)
      ->execute();
  }
  else {
    drupal_goto('photoshare/upgrade');
  }
  drupal_exit(); 
}

