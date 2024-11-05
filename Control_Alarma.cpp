//////////////////////////////////////////////////////////////////
// Materia:  Seminario de Sensores y acondicionamiento de señales
// Proyecto: Incubadora: Sitema de control de Alarma
// Profesor: CARLOS ALBERTO SANCHEZ ROMERO
// Alumno:   Alejando Orozco Romo
// Codigo:   218171511
// Archivo:  Control_Alarma.cpp
// Fecha de edicion: 17/10/2024
//////////////////////////////////////////////////////////////////

//BIBLIOTECAS 

#include "Control_Alarma.h"

void iniciarAlarma() {
  pinMode(buzzerPin, OUTPUT);  // Configura el pin como salida
  desactivarAlarma();          // Asegura que la alarma esté apagada al inicio
}

void activarAlarma() {
  tone(buzzerPin, 1000);       // Emite un sonido de 1000 Hz
}

void desactivarAlarma() {
  noTone(buzzerPin);           // Apaga el sonido
}