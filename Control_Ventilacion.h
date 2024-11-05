//////////////////////////////////////////////////////////////////
// Materia:  Seminario de Sensores y acondicionamiento de señales
// Proyecto: Incubadora: Sitema de control de Ventilacion
// Profesor: CARLOS ALBERTO SANCHEZ ROMERO
// Alumno:   Alejando Orozco Romo
// Codigo:   218171511
// Archivo:  Control_Ventilacion.h
// Fecha de edicion: 17/10/2024
// Nota:    Incluimos la cabecera de arduino, por que como no estamos trabajando en in archivo .ino de arduino, 
//          no tenemos las funciones básicas de este en los archivos .h y cpp. Cuando lo agregamos a estos archivos
//          adquieren todas las funciones de arduino
//
//////////////////////////////////////////////////////////////////
#ifndef CONTROL_VENTILACION_H
#define CONTROL_VENTILACION_H

// BIBLIOTECAS
#include <Arduino.h>

// PINS para los relés del ventilador
#define VentiladorCalefaccion 6
#define VentiladorEntrada 7
#define VentiladorSalida 8

// DEFINIMOS FUNCIONES 
void iniciarVentiladores();

//VENTILADOR DE ENTRADA
void activarVentiladorEntrada();
void desactivarVentiladorEntrada();
//VENTILADOR DE SALIDA
void activarVentiladorSalida();
void desactivarVentiladorSalida();  // Corrección aquí
//VENTILADOR DE CALEFACCION
void activarVentiladorCalefaccion();
void desactivarVentiladorCalefaccion();


#endif




