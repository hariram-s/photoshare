<?php
/**
 * @file
 * photoshare_feature.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function photoshare_feature_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation:admin/config/photoshare/image-management-page
  $menu_links['navigation:admin/config/photoshare/image-management-page'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'admin/config/photoshare/image-management-page',
    'router_path' => 'admin/config/photoshare/image-management-page',
    'link_title' => 'Image management',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: navigation:admin/config/photoshare/spam-reported-images
  $menu_links['navigation:admin/config/photoshare/spam-reported-images'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'admin/config/photoshare/spam-reported-images',
    'router_path' => 'admin/config/photoshare/spam-reported-images',
    'link_title' => 'Spam reported images',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: navigation:node/add
  $menu_links['navigation:node/add'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add',
    'router_path' => 'node/add',
    'link_title' => 'Add content',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: navigation:node/add/album
  $menu_links['navigation:node/add/album'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/album',
    'router_path' => 'node/add/album',
    'link_title' => 'Photoshare Album',
    'options' => array(
      'attributes' => array(
        'title' => 'Album stores images.',
      ),
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'node/add',
  );
  // Exported menu link: navigation:node/add/image
  $menu_links['navigation:node/add/image'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/image',
    'router_path' => 'node/add/image',
    'link_title' => 'Photoshare Image',
    'options' => array(
      'attributes' => array(
        'title' => 'Image content type stores all the information like title and to which category and album the image belongs to.',
      ),
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'node/add',
  );
  // Exported menu link: navigation:photostream
  $menu_links['navigation:photostream'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'photostream',
    'router_path' => 'photostream',
    'link_title' => 'All Images',
    'options' => array(
      'attributes' => array(
        'title' => 'This page displays all the images in the website.',
      ),
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Add content');
  t('All Images');
  t('Image management');
  t('Photoshare Album');
  t('Photoshare Image');
  t('Spam reported images');


  return $menu_links;
}
