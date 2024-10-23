//////////////////////////////////////////////////////////////////
// Materia:  Seminario de Sensores y acondicionamiento de señales
// Proyecto: Incubadora: Pantalla LCD 4x24
// Profesor: CARLOS ALBERTO SANCHEZ ROMERO
// Alumno:   Alejando Orozco Romo
// Codigo:   218171511
// Archivo:  LCD.h
// Fecha de edicion: 22/10/2024
//////////////////////////////////////////////////////////////////

#ifndef LCD_H
#define LCD_H

// BIBLIOTECAS
#include <Arduino.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

extern LiquidCrystal_I2C lcd;
void iniciarLCD();

#endif