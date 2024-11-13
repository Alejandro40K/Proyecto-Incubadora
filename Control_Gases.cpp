//////////////////////////////////////////////////////////////////
// Materia:  Seminario de Sensores y acondicionamiento de señales
// Proyecto  Incubadora
// Profesor: CARLOS ALBERTO SANCHEZ ROMERO
// Alumno:   Alejando Orozco Romo
// Codigo:   218171511
// Archivo:  Control_Gases.cpp
// Fecha de edicion: 05/11/2024
//////////////////////////////////////////////////////////////////

//*******************************************************BIBLIOTECAS******************************************************************************//
#include "Control_Gases.h"
#include "LCD.h" 

//***************************************************DEFINICION VARIABLES*************************************************************************//
int valorSensor = 0;

//**************************************************FUNCIONES SENSOR DE GAS***********************************************************************//
void iniciarControlGases(){
  Serial.begin(9600);
  pinMode(MQ7Pin, INPUT);
}

void leerGases() {
  valorSensor = analogRead(MQ7Pin);
  float ppm = (valorSensor / 1023.0) * 5000.0;  
  lcd.setCursor(10, 1);
  lcd.print("CO:");
  lcd.print(ppm);
  lcd.setCursor(13, 2);
  lcd.print("ppm");
}
