//////////////////////////////////////////////////////////////////
// Materia:  Seminario de Sensores y acondicionamiento de señales
// Proyecto: Incubadora: Sitema de control de humedad
// Profesor: CARLOS ALBERTO SANCHEZ ROMERO
// Alumno:   Alejando Orozco Romo
// Codigo:   218171511
// Archivo:  Control_humedad.h
// Fecha de edicion: 15/10/2024
// Nota: 
//      Incluimos la cabecera de arduino, por que como no estamos trabajando en in archivo .ino de arduino, 
//      no tenemos las funciones básicas de este en los archivos .h y cpp. Cuando lo agregamos a estos archivos
//      adquieren todas las funciones de arduino*/
//////////////////////////////////////////////////////////////////

#ifndef CONTROL_HUMEDAD_H
#define CONTROL_HUMEDAD_H

// BIBLIOTECAS
#include <Arduino.h>
#include <Wire.h>
#include <DHT.h>
#define DHTTYPE DHT11


// PINES DEL ARDUINO UNO
#define DHTPIN 3 	 // Pin para el sensor DHT11
#define relePin 5    // Pin para controlar el rele
#define TRIGGER_PIN 11
#define ECHO_PIN 12

//VARIABLES EXTERNAS
// variables sensor DHT11
extern DHT dht; 
extern float humedad;
// varriables externas sensor ultrasonico
extern long tiempo;
extern int distancia;
extern int nueva_distancia;
extern float velocidad;

//DECLARACION DE FUNCIONES 

void iniciarSistemaHumidificador();
void leerHumedad();
//funciones para controlar el humidificador desde el RTC
void controlarHumidificadorAntes19();
void controlarHumidificadorDespues19();



//void comenzarProgramaHumidificador();//FUCNCION DE PRUEBA
//void mostrarHumedad();
//completar: enviara una señal cuando el nivel este bajo al numero de celular
//void nivelTanque();
//void iniciarUltrasonico();
//void controlarHumidificador();

#endif


