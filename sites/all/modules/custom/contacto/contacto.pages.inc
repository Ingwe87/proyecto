<?php
// $id$

/**
 * Definir el formulario.
 */
function contacto_form() {
  $form['user_name'] = array(
      '#title' => t('Your name'),
      '#type' => 'textfield',
      '#description' => t('Por favor ingresa tu nombre.'),
  );
  $form['apellido'] = array(
  		'#title' => t('Apellidos'),
  		'#type' => 'textfield',
  		'#description' => t('Por favor ingresa tus apellidos.'),
  );
  $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Enviar')
  );
  return $form;
}

/**
 * Validar el formulario.
 */
  function contacto_form_validate($form, &$form_state){
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
  function contacto_form_submit($form, &$form_state){
    $name = $form_state['values']['user_name'];
    drupal_set_message(t('Gracias por enviarnos sus datos, %name',
        array('%name' => $name)));
  }