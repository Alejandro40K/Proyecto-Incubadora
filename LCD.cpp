//////////////////////////////////////////////////////////////////
// Materia:  Seminario de Sensores y acondicionamiento de señales
// Proyecto: Incubadora: Pantalla LCD 4x24
// Profesor: CARLOS ALBERTO SANCHEZ ROMERO
// Alumno:   Alejando Orozco Romo
// Codigo:   218171511
// Archivo:  LCD.cpp
// Fecha de edicion: 22/10/2024
//////////////////////////////////////////////////////////////////

//BIBLIOTECAS 
#include "LCD.h"

LiquidCrystal_I2C lcd(0x27,20,4);

void iniciarLCD(){
  //Inicializamos la pantalla LCD
  lcd.init();
  //Encendemos pantalla LCD
  lcd.backlight();
}


