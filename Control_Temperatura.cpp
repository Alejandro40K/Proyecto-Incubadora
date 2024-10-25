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

//BIBLIOTECAS 
#include "Control_Temperatura.h"
#include "Control_Alarma.h"
#include "LCD.h"

//Definimos objetos funciones extern
OneWire ourWire(2);           
DallasTemperature sensors(&ourWire);
float temp;

void IniciarSistemaTemperatura(){
  delay(1000);
  Serial.begin(9600);
  sensors.begin();
  iniciarAlarma();
}

void leerTemperatura(){
  
  sensors.requestTemperatures();   //Se envía el comando para leer la temperatura
  temp= sensors.getTempCByIndex(0); //Se obtiene la temperatura en ºC

  if(temp == -127.00){
    //Agregar mensaje de errir de sensor en LCD 
    Serial.println("Error al leer del sensor de Temperatura DS18B20");
  }else{
      lcd.setCursor(0, 3);
      lcd.print("Temperatura: ");
      lcd.print(temp);
      lcd.print(" C");
  }
  
}

 void ControlarTemperaturaAntes19(){
  leerTemperatura();
  ControlAlarmaTemperaturaAntes19();
}
 void ControlarTemperaturaDespues19(){
  leerTemperatura();
  ControlAlarmaTemperaturaDespues19() ;
}
  
void ControlAlarmaTemperaturaAntes19() {
    if (temp > 30) {
        activarAlarma();  // Activa la alarma si la temperatura es alta
        Serial.println("¡Alerta! Temperatura crítica");
    } else {
        desactivarAlarma();
    }
}

void ControlAlarmaTemperaturaDespues19() {
    if (temp > 29) {
        activarAlarma();  // Activa la alarma si la temperatura es alta
        Serial.println("¡Alerta! Temperatura crítica");
    } else {
        desactivarAlarma();
    }
}


/*
void mostrarTemperatura(){
  //lcd.clear();
  lcd.setCursor(0, 3);
  lcd.print("Temperatura: ");
  lcd.print(temp);
  lcd.print(" C");
}
/

/* PARA HACER PRUEBAS 
void comenzarProgramaTemperatura(){
  ControlarTemperatura();
  ControlAlarmaTemperatura();

}

//Por definir
void ControlResistenciaTermica(){

}


*/
