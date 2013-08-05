<?php

/**
 * @file
 * Theme implementation to display a single Drupal page.
 *
 * items an array which contains: 
 * - title: title of the image.
 * - image: Holds the image url.
 * - user_name: name of the author
 * - nid: Id of the node.
 * - user_id: Id of the particular user.
 * - premium: sets 1 if the album is added by premium user.
 * - remove_spam: sets 0 or 1 by default.
 *
 * @see photoshare_theme().
 */
?>
<div <?php if ($premium == '1') : ?>class="photostream-premium-album"
  <?php else : ?>class="photostream-album" <?php endif; ?>>
  <div class="photostream-title">Title:<?php print $title; ?></div>
  <div class="photostream-image">
    <a href = "<?php print $url; ?>" >
    <img src="<?php print $image; ?>"/>
    </a>
  </div>
  <div class="photostream-user-name">
    <?php print "Updated by: " . l(t($user_name), "photostream/" . $user_name); ?>
  </div>
  <?php if (!$remove_spam) : ?>
  <div class="photostream-report-spam"><a href = "<?php print $spam_url; ?>" >Report Spam or abuse</a></div>
  <?php endif; ?>
</div>

