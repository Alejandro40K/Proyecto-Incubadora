//////////////////////////////////////////////////////////////////
// Materia:  Seminario de Sensores y acondicionamiento de señales
// Proyecto: Incubadora - Main Principal 
// Profesor: CARLOS ALBERTO SANCHEZ ROMERO
// Alumno:   Alejando Orozco Romo
// Codigo:   218171511
// Archivo:  Sistema_de_Humedad.ino
// Fecha de edicion: 15/10/2024
// NOTAS:
//      EVITAR NUMEROS MAGICOS, AGREGAR VARIABLES PARA 
//      CONTRARESTARLOS, COMO HUMEDAD MAXIMA, MINIMA, ETC. 
//////////////////////////////////////////////////////////////////

#include "Control_humedad.h"
#include "Control_Temperatura.h"
#include "Control_Sistema.h"



void setup() {
  IniciarRTC();

  //iniciarSistemaHumidificador();
  //IniciarSistemaTemperatura();
   
}

void loop() {
  comenzarSistema();
  delay(2000);
    //comenzarProgramaHumidificador();
    //comenzarProgramaTemperatura();*/
    /*actualizarEstadoIncubacion();  // Actualizar control del humidificador según los días
    mostrarInformacion();          // Mostrar días transcurridos y humedad en LCD
    delay(2000);    */
}