<?php

function photoshare_download_image_page($nid, $style) {
  global $user;
  $image_info = image_get_info('public://photoshare/private/' . $nid . '_' . $style);
  $query = "SELECT field_ps_image_fid FROM {field_data_field_ps_image} WHERE entity_id=:entity_id";
  $result = db_query($query, array(':entity_id' => $nid));
  $file_id = $result->fetchAssoc();
  $fid = $file_id['field_ps_image_fid'];
  $uid = $user->uid;
  $time = time();
  $download_info = array(
    'user_id' => $uid,
    'fid' => $fid,
    'download_time' => $time,
    'download_size' => $style,
  );
  $result = db_insert('ps_image_downloads')
    ->fields($download_info)
    ->execute();
  if (!$image_info) {
    $file = file_load($fid);
    $file_name = $file->filename;
    $file_info = pathinfo($file_name);
    $extension = $file_info['extension'];
    $destination = "public://photoshare/private/" . $nid . "_" . $style . '.' . $extension;
    $source = $file->uri;
    $photoshare_image_style = 'ps-' . $style;
    $image_style = image_style_load($photoshare_image_style);
    $create_image_style = image_style_create_derivative($image_style, $source, $destination);
  }
  $image_extension = !empty($image_info)?$image['extension']:$extension; 
  if ($style == 'original') {
    $user = user_load($user->uid);
    $roles = $user->roles;
    $premium_user = in_array('premium user', $roles);
    $administrator = in_array('administrator', $roles);
    $node = node_load($nid);
    $author = ($node->uid == $user->uid);
    if ($premium_user || $administrator || $author) {  
      $file_name = drupal_realpath('public://photoshare/private/' . $nid . '_' . $style . '.' . $image_extension);
    }
    else {
      drupal_goto('photoshare/upgrade');
    }
  }
  else { 
    $file_name = drupal_realpath('public://photoshare/private/' . $nid . '_' . $style . '.' . $image_extension);
  }
  
  $value = 'image/' . $image_extension; 
  header("Content-type: " . $value);
  header("Cache-Control: no-store, no-cache, must-revalidate");
  header("Cache-Control: post-check=0, pre-check=0", FALSE);
  header("Pragma: no-cache");
  header("Content-Disposition: attachment; filename=" . $file_name );
  $size= filesize($file_name);
  header("Content-Length: $size bytes");
  readfile($file_name);
  drupal_exit(); 
}
