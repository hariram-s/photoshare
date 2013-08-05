<?php
/**
 * @file
 * photoshare_feature.features.inc
 */

/**
 * Implements hook_views_api().
 */
function photoshare_feature_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function photoshare_feature_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: selected_images
  $nodequeues['selected_images'] = array(
    'qid' => '1',
    'name' => 'selected_images',
    'title' => 'Selected Images',
    'subqueue_title' => '',
    'size' => '12',
    'link' => 'Add',
    'link_remove' => 'Remove',
    'owner' => 'nodequeue',
    'show_in_ui' => '1',
    'show_in_tab' => '1',
    'show_in_links' => '1',
    'reference' => '0',
    'reverse' => '0',
    'i18n' => '0',
    'subqueues' => '1',
    'types' => array(
      0 => 'image',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_image_default_styles().
 */
function photoshare_feature_image_default_styles() {
  $styles = array();

  // Exported image style: ps-large.
  $styles['ps-large'] = array(
    'name' => 'ps-large',
    'effects' => array(
      12 => array(
        'label' => 'Aspect switcher',
        'help' => 'Use different effects depending on whether the image is landscape of portrait shaped. This re-uses other preset definitions, and just chooses between them based on the rule.',
        'effect callback' => 'canvasactions_aspect_image',
        'dimensions callback' => 'canvasactions_aspect_dimensions',
        'form callback' => 'canvasactions_aspect_form',
        'summary theme' => 'canvasactions_aspect_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_aspect',
        'data' => array(
          'portrait' => 'ps-large-portrait',
          'landscape' => 'ps-large-landscpe',
          'ratio_adjustment' => '1',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: ps-large-landscpe.
  $styles['ps-large-landscpe'] = array(
    'name' => 'ps-large-landscpe',
    'effects' => array(
      7 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '1200',
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: ps-large-portrait.
  $styles['ps-large-portrait'] = array(
    'name' => 'ps-large-portrait',
    'effects' => array(
      8 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => '1200',
          'upscale' => 1,
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: ps-medium.
  $styles['ps-medium'] = array(
    'name' => 'ps-medium',
    'effects' => array(
      11 => array(
        'label' => 'Aspect switcher',
        'help' => 'Use different effects depending on whether the image is landscape of portrait shaped. This re-uses other preset definitions, and just chooses between them based on the rule.',
        'effect callback' => 'canvasactions_aspect_image',
        'dimensions callback' => 'canvasactions_aspect_dimensions',
        'form callback' => 'canvasactions_aspect_form',
        'summary theme' => 'canvasactions_aspect_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_aspect',
        'data' => array(
          'portrait' => 'ps-medium-portrait',
          'landscape' => 'ps-medium-landscape',
          'ratio_adjustment' => '1',
        ),
        'weight' => '1',
      ),
      17 => array(
        'label' => 'Overlay (watermark)',
        'help' => 'Choose the file image you wish to use as an overlay, and position it in a layer on top of the canvas.',
        'effect callback' => 'canvasactions_file2canvas_image',
        'dimensions passthrough' => TRUE,
        'form callback' => 'canvasactions_file2canvas_form',
        'summary theme' => 'canvasactions_file2canvas_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_file2canvas',
        'data' => array(
          'xpos' => 'left',
          'ypos' => 'top',
          'alpha' => '100',
          'path' => 'module://photoshare/watermark/photoshare-watermark.png',
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: ps-medium-landscape.
  $styles['ps-medium-landscape'] = array(
    'name' => 'ps-medium-landscape',
    'effects' => array(
      5 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '800',
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => '1',
      ),
      18 => array(
        'label' => 'Overlay (watermark)',
        'help' => 'Choose the file image you wish to use as an overlay, and position it in a layer on top of the canvas.',
        'effect callback' => 'canvasactions_file2canvas_image',
        'dimensions passthrough' => TRUE,
        'form callback' => 'canvasactions_file2canvas_form',
        'summary theme' => 'canvasactions_file2canvas_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_file2canvas',
        'data' => array(
          'xpos' => 'left',
          'ypos' => 'top',
          'alpha' => '100',
          'path' => 'module://photoshare/watermark/photoshare-watermark.png',
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: ps-medium-portrait.
  $styles['ps-medium-portrait'] = array(
    'name' => 'ps-medium-portrait',
    'effects' => array(
      6 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => '800',
          'upscale' => 1,
        ),
        'weight' => '1',
      ),
      19 => array(
        'label' => 'Overlay (watermark)',
        'help' => 'Choose the file image you wish to use as an overlay, and position it in a layer on top of the canvas.',
        'effect callback' => 'canvasactions_file2canvas_image',
        'dimensions passthrough' => TRUE,
        'form callback' => 'canvasactions_file2canvas_form',
        'summary theme' => 'canvasactions_file2canvas_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_file2canvas',
        'data' => array(
          'xpos' => 'left',
          'ypos' => 'top',
          'alpha' => '100',
          'path' => 'module://photoshare/watermark/photoshare-watermark.png',
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: ps-medium-watermark.
  $styles['ps-medium-watermark'] = array(
    'name' => 'ps-medium-watermark',
    'effects' => array(
      1 => array(
        'label' => 'Aspect switcher',
        'help' => 'Use different effects depending on whether the image is landscape of portrait shaped. This re-uses other preset definitions, and just chooses between them based on the rule.',
        'effect callback' => 'canvasactions_aspect_image',
        'dimensions callback' => 'canvasactions_aspect_dimensions',
        'form callback' => 'canvasactions_aspect_form',
        'summary theme' => 'canvasactions_aspect_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_aspect',
        'data' => array(
          'portrait' => 'ps-medium-portrait',
          'landscape' => 'ps-medium-landscape',
          'ratio_adjustment' => '1',
        ),
        'weight' => '1',
      ),
      2 => array(
        'label' => 'Overlay (watermark)',
        'help' => 'Choose the file image you wish to use as an overlay, and position it in a layer on top of the canvas.',
        'effect callback' => 'canvasactions_file2canvas_image',
        'dimensions passthrough' => TRUE,
        'form callback' => 'canvasactions_file2canvas_form',
        'summary theme' => 'canvasactions_file2canvas_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_file2canvas',
        'data' => array(
          'xpos' => 'left',
          'ypos' => 'top',
          'alpha' => '100',
          'path' => 'module://photoshare/watermark/photoshare-watermark.png',
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: ps-original.
  $styles['ps-original'] = array(
    'name' => 'ps-original',
    'effects' => array(),
  );

  // Exported image style: ps-small.
  $styles['ps-small'] = array(
    'name' => 'ps-small',
    'effects' => array(
      10 => array(
        'label' => 'Aspect switcher',
        'help' => 'Use different effects depending on whether the image is landscape of portrait shaped. This re-uses other preset definitions, and just chooses between them based on the rule.',
        'effect callback' => 'canvasactions_aspect_image',
        'dimensions callback' => 'canvasactions_aspect_dimensions',
        'form callback' => 'canvasactions_aspect_form',
        'summary theme' => 'canvasactions_aspect_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_aspect',
        'data' => array(
          'portrait' => 'ps-small-portrait',
          'landscape' => 'ps-small-landscape',
          'ratio_adjustment' => '1',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: ps-small-landscape.
  $styles['ps-small-landscape'] = array(
    'name' => 'ps-small-landscape',
    'effects' => array(
      3 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '400',
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: ps-small-portrait.
  $styles['ps-small-portrait'] = array(
    'name' => 'ps-small-portrait',
    'effects' => array(
      4 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => '400',
          'upscale' => 1,
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: ps-thumbnail.
  $styles['ps-thumbnail'] = array(
    'name' => 'ps-thumbnail',
    'effects' => array(
      9 => array(
        'label' => 'Aspect switcher',
        'help' => 'Use different effects depending on whether the image is landscape of portrait shaped. This re-uses other preset definitions, and just chooses between them based on the rule.',
        'effect callback' => 'canvasactions_aspect_image',
        'dimensions callback' => 'canvasactions_aspect_dimensions',
        'form callback' => 'canvasactions_aspect_form',
        'summary theme' => 'canvasactions_aspect_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_aspect',
        'data' => array(
          'portrait' => 'ps-thumbnail-portrait',
          'landscape' => 'ps-thumbnail-landscape',
          'ratio_adjustment' => '1',
        ),
        'weight' => '1',
      ),
      15 => array(
        'label' => 'Overlay (watermark)',
        'help' => 'Choose the file image you wish to use as an overlay, and position it in a layer on top of the canvas.',
        'effect callback' => 'canvasactions_file2canvas_image',
        'dimensions passthrough' => TRUE,
        'form callback' => 'canvasactions_file2canvas_form',
        'summary theme' => 'canvasactions_file2canvas_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_file2canvas',
        'data' => array(
          'xpos' => 'left',
          'ypos' => 'top',
          'alpha' => '100',
          'path' => 'module://photoshare/watermark/photoshare-watermark.png',
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: ps-thumbnail-landscape.
  $styles['ps-thumbnail-landscape'] = array(
    'name' => 'ps-thumbnail-landscape',
    'effects' => array(
      1 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '100',
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => '1',
      ),
      16 => array(
        'label' => 'Overlay (watermark)',
        'help' => 'Choose the file image you wish to use as an overlay, and position it in a layer on top of the canvas.',
        'effect callback' => 'canvasactions_file2canvas_image',
        'dimensions passthrough' => TRUE,
        'form callback' => 'canvasactions_file2canvas_form',
        'summary theme' => 'canvasactions_file2canvas_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_file2canvas',
        'data' => array(
          'xpos' => 'left',
          'ypos' => 'top',
          'alpha' => '100',
          'path' => 'module://photoshare/watermark/photoshare-watermark.png',
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: ps-thumbnail-portrait.
  $styles['ps-thumbnail-portrait'] = array(
    'name' => 'ps-thumbnail-portrait',
    'effects' => array(
      2 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => '100',
          'upscale' => 1,
        ),
        'weight' => '1',
      ),
      14 => array(
        'label' => 'Overlay (watermark)',
        'help' => 'Choose the file image you wish to use as an overlay, and position it in a layer on top of the canvas.',
        'effect callback' => 'canvasactions_file2canvas_image',
        'dimensions passthrough' => TRUE,
        'form callback' => 'canvasactions_file2canvas_form',
        'summary theme' => 'canvasactions_file2canvas_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_file2canvas',
        'data' => array(
          'xpos' => 'left',
          'ypos' => 'top',
          'alpha' => '100',
          'path' => 'module://photoshare/watermark/photoshare-watermark.png',
        ),
        'weight' => '2',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function photoshare_feature_node_info() {
  $items = array(
    'album' => array(
      'name' => t('Photoshare Album'),
      'base' => 'node_content',
      'description' => t('Album stores images.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'image' => array(
      'name' => t('Photoshare Image'),
      'base' => 'node_content',
      'description' => t('Image content type stores all the information like title and to which category and album the image belongs to.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
