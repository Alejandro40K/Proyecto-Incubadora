//////////////////////////////////////////////////////////////////
// Materia:  Seminario de Sensores y acondicionamiento de señales
// Proyecto: Incubadora: Sitema de control de humedad
// Profesor: CARLOS ALBERTO SANCHEZ ROMERO
// Alumno:   Alejando Orozco Romo
// Codigo:   218171511
// Archivo:  Control_Temperatura.cpp
// Fecha de edicion: 16/10/2024
// NOTAS: Funcion leerTemperatura, posiblemente redundante
//////////////////////////////////////////////////////////////////

//***********************************************************BIBLIOTECAS***************************************************************************//
#include "Control_Temperatura.h"
#include "Control_Alarma.h"
#include "Control_Ventilacion.h"
#include "LCD.h"

//***********************************************************DEFINIMOS OBJETOS*********************************************************************//
OneWire ourWire(2);           
DallasTemperature sensors(&ourWire);

//********************************************************DEFINICION VARIABLES*********************************************************************//
float temp;

//**********************************************************FUNCIONES TEMPERATURA******************************************************************//
void IniciarSistemaTemperatura(){
    delay(1000);
    Serial.begin(9600);
    sensors.begin();
    iniciarAlarma();
    iniciarVentiladores(); 
}

void leerTemperatura(){
    sensors.requestTemperatures();   
    temp = sensors.getTempCByIndex(0);

    if(temp == -127.00){
        lcd.setCursor(0, 3);
        lcd.print("Ta:Error");
        Serial.println("Error al leer del sensor de Temperatura DS18B20");
    } else {
        lcd.setCursor(0, 3);
        lcd.print("Ta:");
        lcd.print(temp);
        lcd.print("C");
    }
}

//FUNCIONES DE CONTROL 
/*void ControlarTemperaturaAntes19() {
    leerTemperatura();
    if (temp > 30) {
        activarAlarma();  // Activa la alarma si la temperatura es alta
        Serial.println("¡Alerta! Temperatura crítica");
        desactivarVentiladorCalefaccion(); // Apaga el ventilador si supera 30 °C
    } else {
        desactivarAlarma();
        activarVentiladorCalefaccion(); // Enciende el ventilador si la temperatura está bajo 30 °C
    }
}

void ControlarTemperaturaDespues19() {
    leerTemperatura();
    if (temp > 29) {
        activarAlarma();  // Activa la alarma si la temperatura es alta
        Serial.println("¡Alerta! Temperatura crítica");
        desactivarVentiladorCalefaccion(); // Apaga el ventilador si supera 29 °C
    } else {
        desactivarAlarma();
        activarVentiladorCalefaccion(); // Enciende el ventilador si la temperatura está bajo 29 °C
    }
}*/



// FUNCION PARA HACER PRUEBAS 
/*
void comenzarProgramaTemperatura(){
  ControlarTemperatura();
  ControlAlarmaTemperatura();

}

//Por definir
void ControlResistenciaTermica(){

}*/


