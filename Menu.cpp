//////////////////////////////////////////////////////////////////
// Materia:  Seminario de Sensores y acondicionamiento de señales
// Proyecto: Incubadora: Sitema de control de humedad
// Profesor: CARLOS ALBERTO SANCHEZ ROMERO
// Alumno:   Alejando Orozco Romo
// Codigo:   218171511
// Archivo:  Menu.cpp
// Fecha de edicion: 22/10/2024
// Nota: 
//      Agregar capacitores del desacoplo para que se filtre el riuido generado por el relé
/* Hcer una funcion siblple que ñllame la funcion de mostrarinfo desde el sistema de control, luego de ahi llamarla en el main.ino. funcipnes 
simples*/
//////////////////////////////////////////////////////////////////

//BIBLIOTECAS 
#include "Menu.h"


void iniciarSistemaTotal(){
  IniciarRTC();
}
void mostrarmanu(){
  comenzarSistema();
}



