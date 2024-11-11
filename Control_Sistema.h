
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

//VARIABLES EXTERNAS 
extern RTC_DS1307 rtc;
extern DateTime fechaInicioIncubacion; 


void IniciarRTC();
int obtenerDiaIncubacion();
void actualizarEstadoIncubacion();
void mostrarInformacion();
//funcion para comensar el sistema
void comenzarSistema();
//Funcion para inicializar todos los componentes del sistema
void iniciarComponentes();
void leerRTC();
#endif