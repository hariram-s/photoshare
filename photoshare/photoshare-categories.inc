<?php

/**
 * @file
 *  categories block implementation.
 */

/**
 * The function is used to display the list of categories in the block.
 *
 * @returns $data.
 */
function _photoshare_list_categories() {
  $data = array();
  $query = "";
  $query .= " SELECT taxonomy_term_data.name ";
  $query .= " FROM {taxonomy_term_data} ";
  $query .= " JOIN {taxonomy_vocabulary} ";
  $query .= " ON taxonomy_term_data.vid = taxonomy_vocabulary.vid ";
  $query .= " WHERE taxonomy_vocabulary.name = :name";
  $result = db_query($query, array(':name' => 'Categories'));
  
  foreach ($result as $record) {
    $link = l($record->name, "photostream/categories/" . $record->name);
    $names['items'][] = $link;
  }
  if (empty($names['items'])) {
    $msg = "No categories added yet";
    return $msg;
  }
  $data = array (
    '#items' => $names,
    '#theme' => 'item_list',
  );
  return $data;
}

