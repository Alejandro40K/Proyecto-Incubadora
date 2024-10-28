//////////////////////////////////////////////////////////////////
// Materia:  Seminario de Sensores y acondicionamiento de señales
// Proyecto: Incubadora: Sitema de control de humedad
// Profesor: CARLOS ALBERTO SANCHEZ ROMERO
// Alumno:   Alejando Orozco Romo
// Codigo:   218171511
// Archivo:  Control_humedad.cpp
// Fecha de edicion: 15/10/2024
// Nota: 
//      Agregar capacitores del desacoplo para que se filtre el riuido generado por el relé
//////////////////////////////////////////////////////////////////


//BIBLIOTECAS
#include "Control_humedad.h"
#include "Control_Ventilacion.h"
#include "LCD.h"
#include "Control_Alarma.h"

//VARIABLES EXTERNAS 
DHT dht(DHTPIN, DHTTYPE); 
float humedad = 0; 
long tiempo;
int distancia;
int nueva_distancia = 0;
float velocidad = 0.01715; 

//FUNCION PARA INICIAR EL HUMIDIFICADOR 
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
}

//FUNCION PARA LEER LA HUMEDAD CON EL SENSOR DHT
void leerHumedad(){
    //Leemos humedad
    humedad = dht.readHumidity();
  
    // Verificar si el sensor está funcionando correctamente
    if (isnan(humedad)) {
        Serial.println("Error al leer del sensor de humedad DHT11");
    } else {
        lcd.setCursor(0, 2);
        lcd.print("Humedad: ");
        lcd.print(humedad);
        lcd.print(" %");
    }
}

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

/*
//FUNCION PARA MOSTRAR LA HUMEDAD 
void mostrarHumedad(){
    lcd.setCursor(0, 2);
    lcd.print("Humedad: ");
    lcd.print(humedad);
    lcd.print(" %");
}*/
////////////////////////////////////////////////////////////////////////////////////////////////


/* para comprobar el funcionamiento dle humidificador
void comenzarProgramaHumidificador(){

  iniciarSistemaHumidificador();
  leerHumedad();
  controlarHumidificadorAntes19();
  //controlarAlarmaHumidificador();
  mostrarHumedad();
}*/


/*
// Funciones del ultrasónico por definir 
void iniciarUltrasonico(){
  // Transmisor de onda ultrasonica
  pinMode(TRIGGER_PIN, OUTPUT); 
  // Receptor de onda ultrasonica
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
}

/*Esta funcion (nivelTanque) será modificada luego para enviar un mensaje por 
celular del nivel de agua, tendra 3 estados, por ejemplo si el 
tanque tiene 10 cm de profundidad, donde 8 son los deseados al maximo, 
y cuatro es la mitad y 2 es poca (con mensaje de alerta de almacenaje),  
enviara todos esos datos, por ejmplo, por semana (a esepcion de los 
mensjes de capacidad baja, que seran enviados cuando sea) al celular*/

/*
void nivelTanque(){
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
  distancia = (tiempo * velocidad);

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  nueva_distancia = distancia;

  delay(500);  
}

*/
