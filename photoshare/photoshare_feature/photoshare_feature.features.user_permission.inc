<?php
/**
 * @file
 * photoshare_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function photoshare_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: access all views.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: access user profiles.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'user',
  );

  // Exported permission: administer nodequeue.
  $permissions['administer nodequeue'] = array(
    'name' => 'administer nodequeue',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: administer permissions.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: administer search.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: administer taxonomy.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: administer users.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: administer views.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: cancel account.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: change own username.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: create album content.
  $permissions['create album content'] = array(
    'name' => 'create album content',
    'roles' => array(
      0 => 'administrator',
      1 => 'photographer',
    ),
    'module' => 'node',
  );

  // Exported permission: create field_ps_image.
  $permissions['create field_ps_image'] = array(
    'name' => 'create field_ps_image',
    'roles' => array(
      0 => 'administrator',
      1 => 'photographer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create image content.
  $permissions['create image content'] = array(
    'name' => 'create image content',
    'roles' => array(
      0 => 'administrator',
      1 => 'photographer',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any album content.
  $permissions['delete any album content'] = array(
    'name' => 'delete any album content',
    'roles' => array(
      0 => 'administrator',
      1 => 'photographer',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any image content.
  $permissions['delete any image content'] = array(
    'name' => 'delete any image content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own album content.
  $permissions['delete own album content'] = array(
    'name' => 'delete own album content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own image content.
  $permissions['delete own image content'] = array(
    'name' => 'delete own image content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete terms in 1.
  $permissions['delete terms in 1'] = array(
    'name' => 'delete terms in 1',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: download page.
  $permissions['download page'] = array(
    'name' => 'download page',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
    ),
    'module' => 'photoshare',
  );

  // Exported permission: edit any album content.
  $permissions['edit any album content'] = array(
    'name' => 'edit any album content',
    'roles' => array(
      0 => 'administrator',
      1 => 'photographer',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any image content.
  $permissions['edit any image content'] = array(
    'name' => 'edit any image content',
    'roles' => array(
      0 => 'administrator',
      1 => 'photographer',
    ),
    'module' => 'node',
  );

  // Exported permission: edit field_ps_image.
  $permissions['edit field_ps_image'] = array(
    'name' => 'edit field_ps_image',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own album content.
  $permissions['edit own album content'] = array(
    'name' => 'edit own album content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own field_ps_image.
  $permissions['edit own field_ps_image'] = array(
    'name' => 'edit own field_ps_image',
    'roles' => array(
      0 => 'administrator',
      1 => 'photographer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own image content.
  $permissions['edit own image content'] = array(
    'name' => 'edit own image content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit terms in 1.
  $permissions['edit terms in 1'] = array(
    'name' => 'edit terms in 1',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: list album images.
  $permissions['list album images'] = array(
    'name' => 'list album images',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'photoshare',
  );

  // Exported permission: list category images.
  $permissions['list category images'] = array(
    'name' => 'list category images',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'photoshare',
  );

  // Exported permission: manipulate all queues.
  $permissions['manipulate all queues'] = array(
    'name' => 'manipulate all queues',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: manipulate queues.
  $permissions['manipulate queues'] = array(
    'name' => 'manipulate queues',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: photoshare spam page.
  $permissions['photoshare spam page'] = array(
    'name' => 'photoshare spam page',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'photoshare',
  );

  // Exported permission: photoshare upgrade page.
  $permissions['photoshare upgrade page'] = array(
    'name' => 'photoshare upgrade page',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
    ),
    'module' => 'photoshare',
  );

  // Exported permission: report spam page.
  $permissions['report spam page'] = array(
    'name' => 'report spam page',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'photoshare',
  );

  // Exported permission: search content.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: select account cancellation method.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: use advanced search.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: user photostream page.
  $permissions['user photostream page'] = array(
    'name' => 'user photostream page',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'photoshare',
  );

  // Exported permission: view field_ps_image.
  $permissions['view field_ps_image'] = array(
    'name' => 'view field_ps_image',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_ps_image.
  $permissions['view own field_ps_image'] = array(
    'name' => 'view own field_ps_image',
    'roles' => array(
      0 => 'administrator',
      1 => 'photographer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view photostream page.
  $permissions['view photostream page'] = array(
    'name' => 'view photostream page',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'photoshare',
  );

  return $permissions;
}
