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
#include <Wire.h>
#include <DHT.h>
// PINES DEL ARDUINO UNO
#define DHTPIN 3 
#define relePin 5    
#define TRIGGER_PIN 9
#define ECHO_PIN 10
#define DHTTYPE DHT11

//VARIABLES EXTERNAS
// variables sensor DHT11
extern DHT dht; 
extern float humedad;
// varriables externas sensor ultrasonico
extern long tiempo;
extern int distancia;
extern int nueva_distancia;
extern float velocidad;

//FUNCIONES PARA EL SENSOR DE HUMEDAD DHT11
void iniciarSistemaHumidificador();
void leerHumedad();

//funciones para controlar el humidificador desde el RTC
//void controlarHumidificadorAntes19();
//void controlarHumidificadorDespues19();

//FUNCIONES PARA EL SENSOR ULTRASÓNICO
void leerNivelTanque();
void iniciarUltrasonico();

//FUNCION DE PRUEBA
//void comenzarProgramaHumidificador();

#endif
