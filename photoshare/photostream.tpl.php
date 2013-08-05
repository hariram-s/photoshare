<?php

/**
 * @file
 * Default theme implementation to display a Images.
 *
 * variables an array contains:
 * - title holds the title of the page
 * -- items an array which contains: 
 * -- title: title of the image.
 * -- image: Holds the image url.
 * -- user_name: name of the author
 * -- nid: Id of the node.
 * -- user_id: Id of the particular user.
 * -- premium: sets 1 if the album is added by premium user.
 * - columns: Number of items to be displayed in a row.
 * 
 * @see photoshare_theme().
 */ 
?>
<div class="photostream">
  <?php if (!empty($title)) : ?>
  <div><h3 class='photostream-title'><?php print $title; ?></h3></div>
  <?php endif; ?>
  <div class="photostream-details">
    <?php for ($i = 0; $i < count($items); $i++) : ?>
    <?php print render($items[$i]); ?>
    <?php endfor; ?>
  </div>
  <div class="photostream-clear"></div>
</div>

