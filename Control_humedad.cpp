//////////////////////////////////////////////////////////////////
// Materia:  Seminario de Sensores y acondicionamiento de señales
// Proyecto: Incubadora: Sitema de control de humedad
// Profesor: CARLOS ALBERTO SANCHEZ ROMERO
// Alumno:   Alejando Orozco Romo
// Codigo:   218171511
// Archivo:  Control_humedad.cpp
// Fecha de edicion: 15/10/2024
//////////////////////////////////////////////////////////////////

#include "Control_humedad.h"

// Definir el objeto DHT
DHT dht(DHTPIN, DHTTYPE); // Aquí es donde lo definimos
// Definición de la variable global
float humedad = 0; // Aquí es donde lo definimos

void iniciarSistema(){
  //Establecemos comunicacion serial
  Serial.begin(9600);
  //iniciamos el sensor DHT11
  dht.begin();
  // Configurar los pines del relé y del buzzer como salida
  pinMode(relePin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  // Inicialmente apagamos el humidificador y el buzzer
  digitalWrite(relePin, HIGH); // Relé apagado
}

void leerHumedad(){
  //leemos humedad
  humedad = dht.readHumidity();
  
  // Verificar si el sensor está funcionando correctamente
  if (isnan(humedad)) {
    Serial.println("Error al leer del sensor de humedad DHT11");
  } else {
    // Mostrar la humedad en el monitor serial
    Serial.print("Humedad: ");
    Serial.print(humedad);
    Serial.println(" %");
  }

}

void controlarHumidificador(){
  //Si la humedad es mayor a 87%, se apaga el humidificador 
   if (humedad > 87) {
    digitalWrite(relePin, HIGH); 
    Serial.println("Humidificador Apagado");
  } 
  //Si la humedad es mayor a 85%, enciende el humidificador 
  else if (humedad < 85) {
    digitalWrite(relePin, LOW); 
    Serial.println("Humidificador Encendido");
  }
}

void controlarAlarma(){
  /*Si la humedad es mayor a 90%, activa la alarma, pues el sistema no esta apagando el humidificador cuando 
  sobrepasa el porcentaje de humedad del ambiente. (luego este porcentaje se modificará dependiendo del ave 
  o del periodo de incubacion)*/

  if (humedad > 95) {
    // Genera un sonido a 1000 H
    tone(buzzerPin, 1000);
    Serial.println("¡Alerta! Humedad critica");
  } else {
    // Apaga el sonido
    noTone(buzzerPin); 
  }
}

void comenzarPrograma(){

  iniciarSistema();
  leerHumedad();
  controlarHumidificador();
  controlarAlarma();

}
