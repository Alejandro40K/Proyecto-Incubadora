//////////////////////////////////////////////////////////////////
// Materia:  Seminario de Sensores y acondicionamiento de señales
// Proyecto: Incubadora: Sitema de control de humedad
// Profesor: CARLOS ALBERTO SANCHEZ ROMERO
// Alumno:   Alejando Orozco Romo
// Codigo:   218171511
// Archivo:  Control_Temperatura.cpp
// Fecha de edicion: 16/10/2024
//////////////////////////////////////////////////////////////////

//BIBLIOTECAS 
#include "Control_Temperatura.h"

//Definimos objetos funciones extern
OneWire ourWire(2);           
DallasTemperature sensors(&ourWire);

void IniciarSistemaTemperatura(){
  delay(1000);
  Serial.begin(9600);
  sensors.begin();
}

void ControlarTemperatura(){
  
  sensors.requestTemperatures();   //Se envía el comando para leer la temperatura
  float temp= sensors.getTempCByIndex(0); //Se obtiene la temperatura en ºC

  if(temp == -127.00){
    Serial.println("Error al leer del sensor de Temperatura DS18B20");
  }else{
    Serial.print("Temperatura= ");
    Serial.print(temp);
    Serial.println(" C");
    delay(500);     
  }
  
}

 
void ControlarSistemaVentilacion(){

}

void ControlarRsistenciaTermica(){

}






