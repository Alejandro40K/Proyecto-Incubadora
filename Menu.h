//////////////////////////////////////////////////////////////////
// Materia:  Seminario de Sensores y acondicionamiento de señales
// Proyecto: Incubadora: Sitema de control de humedad
// Profesor: CARLOS ALBERTO SANCHEZ ROMERO
// Alumno:   Alejando Orozco Romo
// Codigo:   218171511
// Archivo:  Menu.h
// Fecha de edicion: 22/10/2024
// Nota: 
//      
//////////////////////////////////////////////////////////////////

#ifndef MENU_H
#define MENU_H

//BIBLIOTECAS
#include <Arduino.h>
#include <EEPROM.h>
#include <RTClib.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>


//BOTONES PARA EL MENU
#define upButton A1
#define downButton A3
#define selectButton 12
#define backButton 13
#define VentiladorCalefaccion 6

//DEFINIMOS VARIABLES EXTERNAS
extern OneWire;
extern DallasTemperature;
extern float temp;

//FUNCIONES PARA COMENZAR EL PROGRAMA
void iniciarSistemaTotal();
void ComenzarSistemaTotal();

//FUNCIONES PARA LA MEMORIA EEPROM
void leerParametrosEEPROM();
void guardarParametrosEEPROM();
void guardarFechaInicioEEPROM();
void cargarFechaInicioEEPROM();
void guardarFechaFinEEPROM();
void cargarFechaFinEEPROM();

//FUNCIONES PARA EL SUBMENU
void configurarHumedad();
void configurarTemperatura();
void mostrarMargenesHumedad();
void mostrarMargenesTemperatura();
void mostrarMargenesDias();
void configurarDias();
void mostrarEstado();

//FUNCIONES DEL MENU
void displayMainMenu();
void handleMenu();
void mostrarBienvenida();
void iniciarBotones();

//FUNCIONES DE CONTROL 
//Humidificador
void controlarHumidificador();
//Temperatura
void IniciarSistemaTemperatura();
void ControlarTemperatura();
float leerTemperatura();
//RTC dias 
void IniciarRTC();
void iniciarCicloIncubacion();
void configurarDias();
void leerRTC();
int calcularDiasTranscurridos();
void verificarFinCiclo();
void finalizarCiclo();
void apagarSistemas();
void actualizarEstadoIncubacion();

#endif

