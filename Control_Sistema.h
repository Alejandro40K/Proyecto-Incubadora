//////////////////////////////////////////////////////////////////
// Materia:  Seminario de Sensores y acondicionamiento de señales
// Proyecto: Incubadora: Control de Sistema con RTC
// Profesor: CARLOS ALBERTO SANCHEZ ROMERO
// Alumno:   Alejando Orozco Romo
// Codigo:   218171511
// Archivo:  Control_Ventilacion.h
// Fecha de edicion: 21/10/2024
//////////////////////////////////////////////////////////////////

#ifndef CONTROL_SISTEMA_H
#define CONTROL_SISTEMA_H

// BIBLIOTECAS
#include <Arduino.h>
#include <RTClib.h>
#include "Control_humedad.h"
#include "Control_Temperatura.h"
#include "LCD.h"

extern RTC_DS1307 rtc;
extern DateTime fechaInicioIncubacion;  // Para almacenar el tiempo de inicio

void IniciarRTC();
int obtenerDiaIncubacion();
void actualizarEstadoIncubacion();
void mostrarInformacion();
//funcion para comensar el sistema
void comenzarSistema();

#endif