//////////////////////////////////////////////////////////////////
// Materia:  Seminario de Sensores y acondicionamiento de señales
// Proyecto: Incubadora: Sitema de control de Alarma
// Profesor: CARLOS ALBERTO SANCHEZ ROMERO
// Alumno:   Alejando Orozco Romo
// Codigo:   218171511
// Archivo:  Control_Motor.cpp
// Fecha de edicion: 29/10/2024
//////////////////////////////////////////////////////////////////
/*
#include <Arduino.h> 
#include "Control_Motor.h"

#define RELAY_PIN 11  // Pin conectado al relé

// Variables de temporización
unsigned long previousMillis = 0;  // Tiempo del último cambio
const unsigned long intervalOn = 10000;  // 10 segundos (en milisegundos)
const unsigned long intervalOff = 6 * 60 * 60 * 1000UL;  // 6 horas (en milisegundos)

// Variable para rastrear el estado del relé
bool relayState = true;  // El relé comienza encendido

void setup() {
  initializeRelay();  // Configura el relé al inicio
}

void loop() {
  manageRelayCycle();  // Gestiona el ciclo del relé
}

// Función para inicializar el relé
void initializeRelay() {
  pinMode(RELAY_PIN, OUTPUT);  // Configura el pin como salida
  digitalWrite(RELAY_PIN, LOW);  // Enciende el relé inicialmente (activo en LOW)
  previousMillis = millis();  // Registra el tiempo inicial
}

// Función para gestionar el ciclo del relé
void manageRelayCycle() {
  unsigned long currentMillis = millis();  // Obtén el tiempo actual

  if (relayState) {
    // Si el relé está encendido, verifica si han pasado 10 segundos
    if (currentMillis - previousMillis >= intervalOn) {
      turnRelayOff();  // Apaga el relé
      previousMillis = currentMillis;  // Reinicia el temporizador
    }
  } else {
    // Si el relé está apagado, verifica si han pasado 6 horas
    if (currentMillis - previousMillis >= intervalOff) {
      turnRelayOn();  // Enciende el relé
      previousMillis = currentMillis;  // Reinicia el temporizador
    }
  }
}

// Función para encender el relé
void turnRelayOn() {
  digitalWrite(RELAY_PIN, LOW);  // Enciende el relé (activo en LOW)
  relayState = true;  // Actualiza el estado
}

// Función para apagar el relé
void turnRelayOff() {
  digitalWrite(RELAY_PIN, HIGH);  // Apaga el relé
  relayState = false;  // Actualiza el estado
}
*/
