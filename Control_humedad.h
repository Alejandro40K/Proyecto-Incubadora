//////////////////////////////////////////////////////////////////
// Materia:  Seminario de Sensores y acondicionamiento de señales
// Proyecto: Incubadora: Sitema de control de humedad
// Profesor: CARLOS ALBERTO SANCHEZ ROMERO
// Alumno:   Alejando Orozco Romo
// Codigo:   218171511
// Archivo:  Control_humedad.h
// Fecha de edicion: 15/10/2024
//////////////////////////////////////////////////////////////////

#ifndef CONTROL_HUMEDAD_H
#define CONTROL_HUMEDAD_H

// BIBLIOTECAS
#include <Arduino.h>
/* Incluimos la cabecera de arduino, por que como no estamos trabajando en in archivo .ino de arduino, 
no tenemos las funciones básicas de este en los archivos .h y cpp. Cuando lo agregamos a estos archivos
adquieren todas las funciones de arduino*/

#include <DHT.h>
#define DHTTYPE DHT11


// Pines de arduino 
#define DHTPIN 9 	 // Pin para el sensor DHT11
#define relePin 7    // Pin para controlar el rele
#define buzzerPin 6  // Pin para el buzzer

extern DHT dht; // Declaración de un objeto DHT externo
// Declaración de variables globales
extern float humedad; // Solo declaramos, no definimos


//Declaracion de funciones 
void iniciarSistema();
void leerHumedad();
void controlarHumidificador();
void controlarAlarma();
void comenzarPrograma();

// Cambiar esta funcion a temperatura, Por definir
// void controlVentilacion(); 

#endif


