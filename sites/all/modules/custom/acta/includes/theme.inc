<?php

function acta_listaparticipantes($lista) {
  $lista = unserialize($lista);
  foreach ($lista as $asistente) {
    $output .= $asistente;
  }
  
  return $output;
}