//////////////////////////////////////////////////////////////////
// Materia:  Seminario de Sensores y acondicionamiento de señales
// Proyecto: Incubadora: Sitema de control de Alarma
// Profesor: CARLOS ALBERTO SANCHEZ ROMERO
// Alumno:   Alejando Orozco Romo
// Codigo:   218171511
// Archivo:  Control_Alarma.cpp
// Fecha de edicion: 17/10/2024
//////////////////////////////////////////////////////////////////

//*******************************************************BIBLIOTECAS******************************************************************************//
#include "Control_Alarma.h"

//*****************************************************FUNCIONES BUZZER***************************************************************************//
void iniciarAlarma() {
  pinMode(buzzerPin, OUTPUT); 
  desactivarAlarma();         
}

void activarAlarma() {
  tone(buzzerPin, 1000);    
}

void desactivarAlarma() {
  noTone(buzzerPin);           
}