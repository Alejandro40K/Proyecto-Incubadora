//////////////////////////////////////////////////////////////////
// Materia:  Seminario de Sensores y acondicionamiento de señales
// Proyecto: Incubadora: Sitema de control de Alarma
// Profesor: CARLOS ALBERTO SANCHEZ ROMERO
// Alumno:   Alejando Orozco Romo
// Codigo:   218171511
// Archivo:  Control_Alarma.h
// Fecha de edicion: 17/10/2024
//////////////////////////////////////////////////////////////////

#ifndef CONTROL_ALARMA_H
#define CONTROL_ALARMA_H

// BIBLIOTECAS
#include <Arduino.h>

//PINES PARA EL BUZZER
#define buzzerPin 4  

//FUNCIONES PARA EL BUZZER
void iniciarAlarma();    
void activarAlarma();     
void desactivarAlarma();  

#endif


