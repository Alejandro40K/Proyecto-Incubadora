//////////////////////////////////////////////////////////////////
// Materia:  Seminario de Sensores y acondicionamiento de señales
// Proyecto: Incubadora: Sitema de control de Temperatura
// Profesor: CARLOS ALBERTO SANCHEZ ROMERO
// Alumno:   Alejando Orozco Romo
// Codigo:   218171511
// Archivo:  Control_Temperatura.h
// Fecha de edicion: 16/10/2024
// Nota:    
//////////////////////////////////////////////////////////////////

#ifndef CONTROL_TEMPERATURA_H
#define CONTROL_TEMPERATURA_H

//BIBLIOTECAS
#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

//DEFINIMOS VARIABLES EXTERNAS
extern OneWire;
extern DallasTemperature;
extern float temp;

//FUNCIONES PARA EL SENSOR DE TEMPERATURA
void IniciarSistemaTemperatura();
void leerTemperatura();
void ControlarTemperaturaAntes19();
void ControlarTemperaturaDespues19();

#endif




//void comenzarProgramaTemperatura();
//void ControlResistenciaTermica();
//void mostrarTemperatura();
//void ControlarTemperatura();
