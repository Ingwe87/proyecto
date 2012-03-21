<?php
// $id$

/**
 * Definir el formulario.
 */
function example_form() {
  $form['user_name'] = array(
      '#title' => t('Your name'),
      '#type' => 'textfield',
      '#description' => t('Please enter your name.'), //Siempre en inglés
  );
  $form['telefono'] = array(
  		'#title' => t('Número de teléfono'),
  		'#type' => 'textfield',
  		'#description' => t('Por favor ingresa tu número.'),
  );
  $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Submit')
  );
  return $form;
}

/**
 * Validar el formulario.
 */
  function example_form_validate($form, &$form_state){
    $name = $form_state['values']['user_name'];
    if ($form_state['values']['user_name'] == 'Ruben Egiguren'){
      // Notificamos al API de formulario que el campo a fallado.
      // Campo error, texto error
      form_set_error('user_name',t('%name is not allowed to use in this form.',
          array('%name' => $name)));// Siempre en ingles
    }
  }
  /**
   * Manejador de post-envío del formulario de validación
   */
  function example_form_submit($form, &$form_state){
    $name = $form_state['values']['user_name'];
    drupal_set_message(t('Thanks for filling out the form, %name',
        array('%name' => $name)));
    $name = $form_state['values']['telefono'];
    drupal_set_message(t('Thanks for accept the form, %name',
    		array('%name' => $name)));
  }