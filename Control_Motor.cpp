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
//BIBLIOTECAS 

#include "Control_Motor.h"

// Tiempo en milisegundos para una vuelta completa cada 6 horas
const unsigned long tiempoPorVuelta = 21600000; // 6 horas en milisegundos
const unsigned long tiempoPorPaso = tiempoPorVuelta / pasosPorVuelta; // Tiempo por paso

//INICIAR RTC
// Función para inicializar los pines
void inicializarDriver() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(sleepPin, OUTPUT);
  
  digitalWrite(dirPin, HIGH);   // Configura la dirección inicial
  digitalWrite(sleepPin, HIGH); // Activa el modo de operación del driver
}

// Función para activar el motor
void activarMotor() {
  digitalWrite(enablePin, LOW); // Activa las bobinas del motor
}

// Función para desactivar el motor
void desactivarMotor() {
  digitalWrite(enablePin, HIGH); // Desactiva las bobinas del motor
  digitalWrite(sleepPin, LOW);   // Activa el modo de reposo
}

// Función para mover el motor en una dirección
void moverMotorEnDireccion(int direccion) {
  digitalWrite(dirPin, direccion); // Configura la dirección de rotación
  moverMotor(pasosPorVuelta);      // Mueve el motor el número de pasos especificado
  desactivarMotor();                // Desactiva el motor después de moverlo
}

// Función para mover el motor una cantidad de pasos
void moverMotor(int pasos) {
  for (int i = 0; i < pasos; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500); // Ajusta para controlar la velocidad
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500); // Ajusta para controlar la velocidad
  }
}

//COMENZAR SISTEMA
void iniciarSistemaMotor(){
  moverMotorEnDireccion(HIGH);  // Mueve el motor en una dirección
  delay(tiempoPorVuelta);       // Espera 6 horas antes de la próxima vuelta
  moverMotorEnDireccion(LOW);   // Cambia de dirección y mueve el motor
  delay(tiempoPorVuelta);  
}*/