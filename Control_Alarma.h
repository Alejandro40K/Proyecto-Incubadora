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
#define buzzerPin 4  // Pin 6 digital del arduino para el buzzer

void iniciarAlarma();     // Inicializar el pin del buzzer
void activarAlarma();     // Activar el buzzer
void desactivarAlarma();  // Desactivar el buzzer


#endif


