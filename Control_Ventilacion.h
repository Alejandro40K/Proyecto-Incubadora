//////////////////////////////////////////////////////////////////
// Materia:  Seminario de Sensores y acondicionamiento de señales
// Proyecto: Incubadora: Sitema de control de Ventilacion
// Profesor: CARLOS ALBERTO SANCHEZ ROMERO
// Alumno:   Alejando Orozco Romo
// Codigo:   218171511
// Archivo:  Control_Ventilacion.h
// Fecha de edicion: 17/10/2024
// Nota:   
//////////////////////////////////////////////////////////////////

#ifndef CONTROL_VENTILACION_H
#define CONTROL_VENTILACION_H

// BIBLIOTECAS
#include <Arduino.h>

// PINS PARA LOS RELES DE CALEFACCION Y VENTILACION
#define VentiladorCalefaccion 6
#define VentiladorEntrada 7
#define VentiladorSalida 8

//FUNCION PARA INICIAR VENTILADORES 
void iniciarVentiladores();

//VENTILADOR DE ENTRADA
void activarVentiladorEntrada();
void desactivarVentiladorEntrada();

//VENTILADOR DE SALIDA
void activarVentiladorSalida();
void desactivarVentiladorSalida(); 

//VENTILADOR DE CALEFACCION
void activarVentiladorCalefaccion();
void desactivarVentiladorCalefaccion();

#endif




