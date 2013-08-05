<?php

/**
 * @file
 *  Selected images block implementation.
 */

/**
 * This function will get the selected images from the queue.
 *
 * @return $output
 *
 * @see photoshare.module
 */
function _photoshare_selected_images() {
  $query = ("SELECT qid from {nodequeue_queue} WHERE name = :name");
  $result = db_query($query, array(':name' => 'selected_images'));
  $data = array();
  $data = $result->fetchAssoc();
  $nodes = nodequeue_load_nodes($data['qid'], FALSE, 0, 10);
  if (empty($nodes)) {
    $output = '';
  }
  else {
    $items = array();
    foreach ($nodes as $node) {
      $items[] = array(
        '#node' => $node,
        '#theme' => 'photostream_item',
      );
    }
    $output[] = array(
      '#items' => $items,
      '#attached' => array(
        'css' => array(
          drupal_get_path('module', 'photoshare') . '/css/photostream.css')
      ),
      '#theme' => 'photostream',
    );
  }
  return $output;
}
