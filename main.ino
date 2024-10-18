//////////////////////////////////////////////////////////////////
// Materia:  Seminario de Sensores y acondicionamiento de señales
// Proyecto: Incubadora - Main Principal 
// Profesor: CARLOS ALBERTO SANCHEZ ROMERO
// Alumno:   Alejando Orozco Romo
// Codigo:   218171511
// Archivo:  Sistema_de_Humedad.ino
// Fecha de edicion: 15/10/2024
//////////////////////////////////////////////////////////////////

#include "Control_humedad.h"
#include "Control_Temperatura.h"



void setup() {

  //iniciarSistemaHumidificador();
  IniciarSistemaTemperatura();
   
}

void loop() {

    delay(2000);
    //comenzarProgramaHumidificador();
    comenzarProgramaTemperatura();
}
