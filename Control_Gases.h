//////////////////////////////////////////////////////////////////
// Materia:  Seminario de Sensores y acondicionamiento de señales
// Proyecto  Incubadora
// Profesor: CARLOS ALBERTO SANCHEZ ROMERO
// Alumno:   Alejando Orozco Romo
// Codigo:   218171511
// Archivo:  Control_Gases.h
// Fecha de edicion: 05/11/2024
//////////////////////////////////////////////////////////////////

#ifndef CONTROL_GASES_H
#define CONTROL_GASES_H

//BIBLIOTECAS
#include <Arduino.h>

//PINES PARA EL SENSOR
#define MQ7Pin A0

//FUNCION PARA EL SENSOR DE GAS
void iniciarControlGases();
void leerGases();

#endif