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


// Constantes
const unsigned long tiempoPorVuelta = 21600000; // 6 horas en milisegundos
const int pasosPorVuelta = 200;  // Número de pasos por vuelta (depende del motor)

// Función para inicializar el motor
void inicializarMotor() {
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(ENABLE_PIN, OUTPUT);

  // Inicializar el motor desactivado
  digitalWrite(ENABLE_PIN, HIGH);  // Desactiva el motor al inicio
  digitalWrite(DIR_PIN, HIGH);     // Configura la dirección inicial
}

// Función para activar el motor
void activarMotor() {
  digitalWrite(ENABLE_PIN, LOW);  // Activa las bobinas del motor
}

// Función para desactivar el motor
void desactivarMotor() {
  digitalWrite(ENABLE_PIN, HIGH);  // Desactiva las bobinas del motor
}

// Función para mover el motor una cantidad de pasos en una dirección
void moverMotorEnDireccion(int direccion) {
  digitalWrite(DIR_PIN, direccion);  // Configura la dirección de rotación
  for (int i = 0; i < pasosPorVuelta; i++) {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(1000);  // Ajusta la velocidad
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(1000);  // Ajusta la velocidad
  }
}

// Función para comenzar el ciclo de movimiento
void iniciarSistemaMotor() {
  moverMotorEnDireccion(HIGH);  // Mueve el motor en una dirección
  delay(tiempoPorVuelta);       // Espera 6 horas antes de la próxima vuelta
  moverMotorEnDireccion(LOW);   // Cambia la dirección y mueve el motor
  delay(tiempoPorVuelta);  
}*/
