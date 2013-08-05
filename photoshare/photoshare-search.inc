<?php 

/**
 * @file
 *  Search page implementation.
 */

/** 
 *
 */
function _photoshare_search() {
  $form = drupal_get_form('_photoshare_search_form');
  $output['form'] = $form;
  return $output;
}

/**
 * To display the search page form.
 *
 * @param array $form
 * @param array $form_state
 *
 * @return  $form
 */
function _photoshare_search_form($form, &$form_state, $option = '', $module = NULL, $prompt = NULL) {
  $form['search_field'] = array(
    '#title' => t('Search text'), 
    '#type' => 'textfield',
    '#required' => TRUE,
    '#size' => 20,
    '#default_value' => '',
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );
  return $form;
}

/**
 * Function for search form submit.
 *
 * @param $form
 * @param $form_state
 */
function search_form_submit($form, &$form_state) {
  $option = $form_state['values']['option'];
  drupal_set_message(t('Showing search results'));  
}


/**
 * Function for validating search form
 **/
function _photoshare_search_form_validate($form, &$form_state) {
  if ($form_state['values']['search_field'] == '') {
    form_set_error('keys', t('Please enter some keywords.'));
  }
}

/**
 * Function that execute the search data function.
 *
 * @ returns array
 */
function _photoshare_search_data($option, $module, $conditions = NULL) {
  if (module_hook($module, 'search_execute')) {
    $results = module_invoke($module, 'search_execute', $option, $conditions);
    if (module_hook($module, 'search_page')) {
      return module_invoke($module, 'search_page', $results);
    }
    else {
      return array(
        '#theme' => 'photostream',
        '#results' => $results,
        '#module' => $module,
      );
    }
  }
}
/*
function  _photoshare_search_view($module = NULL, $option = '') {
  $info = FALSE;
  $redirect = FALSE;
  $option = trim($option);
  if (!$option && !empty($_REQUEST['keys'])) {
    $option = trim($_REQUEST['keys']);
  }

  if (!empty($module)) {
    $active_module_info = search_get_info();
    if (isset($active_module_info[$module])) {
      $info = $active_module_info[$module];
    }
  }

  if (empty($info)) {
     $info = search_get_default_module_info();
     $path = 'search/' . $info['path'];
    if ($option) {
      $path .= '/' . $option;
    }
    drupal_goto($path);
  }
  $results = array('#markup' => '');
  if (empty($_POST['form_id']) || $_POST['form_id'] != '_photoshare_search_form') {
    $conditions =  NULL;
    if (isset($info['conditions_callback']) && function_exists($info['conditions_callback'])) {
      $conditions = call_user_func($info['conditions_callback'], $option);
    }
    if ($option || !empty($conditions)) {
      $results = search_data($option, $info['module'], $conditions);
    }
  }
  $build['search_form'] = drupal_get_form('_photoshare_search_form', NULL, $option, $info['module']);
  $build['search_results'] = $results;

  return $build;
}*/
