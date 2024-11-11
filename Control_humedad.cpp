//////////////////////////////////////////////////////////////////
// Materia:  Seminario de Sensores y acondicionamiento de señales
// Proyecto: Incubadora: Sitema de control de humedad
// Profesor: CARLOS ALBERTO SANCHEZ ROMERO
// Alumno:   Alejando Orozco Romo
// Codigo:   218171511
// Archivo:  Control_humedad.cpp
// Fecha de edicion: 15/10/2024
//////////////////////////////////////////////////////////////////

//******************************************************************BIBLIOTECAS**********************************************************************//
#include "Control_humedad.h"
#include "Control_Ventilacion.h"
#include "LCD.h"
#include "Control_Alarma.h"

//****************************************************************DEFINIMOS OBJETOS******************************************************************//
DHT dht(DHTPIN, DHTTYPE); 

//**************************************************************DEFINIMOS VARIABLES******************************************************************//
float humidity = 0; 
long tiempo;
int distancia;
int nueva_distancia = 0;
float velocidad = 0.01715; 
const float distanciaMaxima = 10.0;  // Distancia máxima cuando el tanque está lleno (en cm)
const float distanciaMinima = 0.0;   // Distancia mínima cuando el tanque está vacío (en cm)

//*********************************************************FUNCIONES PARA EL SENSOR DE HUMEDAD*******************************************************//
void iniciarSistemaHumidificador(){
    //Establecemos comunicación serial
    Serial.begin(9600);
    //Iniciamos el sensor DHT11
    dht.begin();
    // Configurar los pines del relé y del buzzer como salida
    pinMode(relePin, OUTPUT);
    // Inicialmente apagamos el humidificador y el buzzer
    digitalWrite(relePin, HIGH); // Relé apagado
    iniciarLCD();
    iniciarUltrasonico();
}

void leerHumedad(){
    //Leemos humedad
    humidity = dht.readHumidity();
  
    // Verificar si el sensor está funcionando correctamente
    if (isnan(humidity)) {
        lcd.setCursor(0, 2);
        lcd.print("Hr:Error");
        Serial.println("Error al leer del sensor de humedad DHT11");
    } else {
        lcd.setCursor(0, 2);
        lcd.print("Hr:");
        lcd.print(humidity);
        lcd.print("%");
    }
}
/*
//FUNCIONES PARA CONTROLAR EL HUMIDIFICADOR 
void controlarHumidificadorAntes19() {
    leerHumedad();
    
    // Si la humedad es mayor a 80%, se apaga el humidificador 
    if (humedad > 80) {
        digitalWrite(relePin, HIGH); 
        Serial.println("Humidificador Apagado");

        // Activar alarma si la humedad es mayor a 85%
        if (humedad > 85) {
            activarAlarma(); 
            Serial.println("¡Alerta! Humedad crítica");
        } else {
            desactivarAlarma();
        }
    } 
    // Si la humedad es menor a 70%, enciende el humidificador 
    else if (humedad < 70) {
        digitalWrite(relePin, LOW); 
        Serial.println("Humidificador Encendido");
    }
}

void controlarHumidificadorDespues19() {
    leerHumedad();
    
    // Si la humedad es mayor a 90%, se apaga el humidificador 
    if (humedad > 90) {
        digitalWrite(relePin, HIGH); 
        Serial.println("Humidificador Apagado");
    } 
    // Si la humedad es menor a 80%, enciende el humidificador 
    else if (humedad < 85) {
        digitalWrite(relePin, LOW); 
        Serial.println("Humidificador Encendido");
    }
    
    // Activar alarma si la humedad es mayor a 90%
    if (humedad > 90) {        
        activarAlarma();
        Serial.println("¡Alerta! Humedad crítica");
    } else {
        desactivarAlarma();
    }
}
*/



//*********************************************************FUNCIONES PARA EL SENSOR ULTRASONICO******************************************************//
void iniciarUltrasonico(){
  // Transmisor de onda ultrasonica
  pinMode(TRIGGER_PIN, OUTPUT); 
  // Receptor de onda ultrasonica
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
}

void leerNivelTanque(){
  // Apagamos el sensor por si está encendido 
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  // Encendemos el sensor después de 2 microsegundos 
  digitalWrite(TRIGGER_PIN, HIGH);
  // Enviamos la onda ultrasónica por 10 microsegundos
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  // `pulseIn` lee un pulso en estado alto, regresará la duración del pulso
  tiempo = pulseIn(ECHO_PIN, HIGH);
  distancia = (tiempo * velocidad);  // Calculamos la distancia en cm

  // Calculamos el porcentaje de lleno del tanque
  float porcentajeLleno = map(distancia, distanciaMaxima, distanciaMinima, 0, 100);  // Mapea la distancia a porcentaje
  
  // Aseguramos que el porcentaje esté dentro del rango [0, 100]
  if (porcentajeLleno < 0) porcentajeLleno = 0;
  if (porcentajeLleno > 100) porcentajeLleno = 100;

  lcd.setCursor(10, 1);
  lcd.print("Pt:");
  lcd.print(porcentajeLleno);
  lcd.print("%");


  delay(500);  
}


// FUNCION PARA PRUEBAS
/*
void comenzarProgramaHumidificador(){

  iniciarSistemaHumidificador();
  /*leerHumedad();
  controlarHumidificadorAntes19();
  //controlarAlarmaHumidificador();
  mostrarHumedad();*/
//}

