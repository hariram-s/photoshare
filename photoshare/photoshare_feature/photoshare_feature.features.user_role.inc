<?php
/**
 * @file
 * photoshare_feature.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function photoshare_feature_user_default_roles() {
  $roles = array();

  // Exported role: photographer.
  $roles['photographer'] = array(
    'name' => 'photographer',
    'weight' => '3',
  );

  // Exported role: premium_user.
  $roles['premium_user'] = array(
    'name' => 'premium_user',
    'weight' => '4',
  );

  return $roles;
}
