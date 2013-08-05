<?php

/**
 * @file
 *  Album block implementation.
 */

/**
 * The function is used to display the list of categories in the block.
 *
 * @returns $data.
 */
function _photoshare_list_user_albums() {
  $data = array();
  $name = arg(1);
  if ($name == 'categories') {
    $data = "";
  }
  else {
    $query = "";
    $query .= " SELECT node.title, node.nid FROM node ";
    $query .= " JOIN users ";
    $query .= " ON node.uid = users . uid ";
    $query .= " WHERE name = :name ";
    $query .= " AND node.type = :type ";
    $result = db_query($query, array(':name' => $name, ':type' => 'album'));
    foreach ($result as $record) {
      $link = l($record->title, "photostream/$name/album/" . $record->nid);
      $names['items'][] = $link;
    }
    $data = array (
      '#items' => $names,
      '#theme' => 'item_list',
    );
  }
  return $data;
}
