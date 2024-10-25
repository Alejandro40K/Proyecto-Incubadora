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
// RECUERDA PENDEJO!!!!!
// FIJATE BIEN EL LAS FUCNIONES, QUERIAS LLAMAR MOSTRAR INFO CUANDO TENIAS QUE LLAMAR DESDE 
// EL MENU COMENZAR SISTEMA DESDE EL control_sistema.h
// Ver que sirve del codigo del menu de Papi CG
/* Haslo paso a paso, simplificado
no uses chad GTP, enfocate aen otras cosas, deja el menu para el final. 
mañana temperatura y ventiladores, limpia codigo y se mas claro en las fucniones
has un diagrama de flujo */
//////////////////////////////////////////////////////////////////


#include "Menu.h"

void setup() {
  //iniciarSistema();

  //iniciarSistemaHumidificador();
  //IniciarSistemaTemperatura();
   
  iniciarSistemaTotal();
  //IniciarRTC();
}


void loop() {
  mostrarmanu();
  delay(2000);
    //comenzarProgramaHumidificador();
    //comenzarProgramaTemperatura();*/
    /*actualizarEstadoIncubacion();  // Actualizar control del humidificador según los días
    mostrarInformacion();          // Mostrar días transcurridos y humedad en LCD
    delay(2000);    */
}