//////////////////////////////////////////////////////////////////
// Materia:  Seminario de Sensores y acondicionamiento de señales
// Proyecto: Incubadora - Main Principal 
// Profesor: CARLOS ALBERTO SANCHEZ ROMERO
// Alumno:   Alejando Orozco Romo
// Codigo:   218171511
// Archivo:  Sistema_de_Humedad.ino
// Fecha de edicion: 15/10/2024
// Vercion: Se eliminaron funciones redundates en las alarmas de humedad y temperatura, ademas de 
//          Funciones para visualizar los datos en las pantallas LCD.
// NOTAS:
//          EVITAR NUMEROS MAGICOS, AGREGAR VARIABLES PARA 
//          CONTRARESTARLOS, COMO HUMEDAD MAXIMA, MINIMA, ETC. 
//          FIJATE BIEN EL LAS FUCNIONES, QUERIAS LLAMAR MOSTRAR INFO CUANDO TENIAS QUE LLAMAR DESDE 
//          EL MENU COMENZAR SISTEMA DESDE EL control_sistema.h
//////////////////////////////////////////////////////////////////


#include "Menu.h"
#include "Control_humedad.h"


void setup() {
  
  iniciarSistemaTotal();

}

void loop() {
  handleMenu();
  controlarHumidificador();
  ControlarTemperatura();
}