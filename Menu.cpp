//////////////////////////////////////////////////////////////////
// Materia:  Seminario de Sensores y acondicionamiento de señales
// Proyecto: Incubadora: Sitema de control de humedad
// Profesor: CARLOS ALBERTO SANCHEZ ROMERO
// Alumno:   Alejando Orozco Romo
// Codigo:   218171511
// Archivo:  Menu.cpp
// Fecha de edicion: 22/10/2024
// Nota: 
//////////////////////////////////////////////////////////////////

//*******************************************************BIBLIOTECAS******************************************************************************//
#include "Menu.h"
#include "Control_Sistema.h"
#include "Control_humedad.h"
#include "Control_Temperatura.h"
#include "Control_Ventilacion.h"
#include "Control_Alarma.h"
#include "Control_Gases.h"
#include "LCD.h"

//***************************************************DEFINICION VARIABLES*************************************************************************//

// Variables para el menú
int menuIndex = 0;      // Índice del menú
int subMenuIndex = 0;   // Índice de los submenús
int currentMenu = 0;    // Menú actual (0: principal, 1: ver datos, 2: configurar, 3: iniciar, 4: estado sistema)
bool inSubMenu = false; // Estado para saber si está dentro de un submenú
// Variables para el estado de los botones
int lastUpState = HIGH;
int lastDownState = HIGH;
int lastSelectState = HIGH;
int lastBackState = HIGH;
// Variables de humedad 
float humedad = 0; 
int humedadMin = 60;  // Valor por defecto mínimo de humedad
int humedadMax = 95;  // Valor por defecto máximo de humedad
// Variables de temperatura
float temperatura = 0;
int temperaturaMin = 24;
int temperaturaMax = 37;

//************************************************FUNCIONES PARA INICIAR SISTEMA*******************************************************************//

void iniciarSistemaTotal(){
  iniciarBotones();
  leerParametrosEEPROM();
  iniciarSistemaHumidificador();
  IniciarSistemaTemperatura();
  mostrarBienvenida();
  displayMainMenu();
  //iniciarComponentes();
}
void ComenzarSistemaTotal(){
  //comenzarSistema();
  handleMenu();
  controlarHumidificador();
  ControlarTemperatura();
}

//******************************************************FUNCIONES EEPROM***************************************************************************//

// Función para leer en la EEPROM
void leerParametrosEEPROM() {
    // Leer `humedadMax` desde la dirección 0
    EEPROM.get(0, humedadMax);
    // Leer `temperaturaMax` desde la dirección 2
    EEPROM.get(2, temperaturaMax);

    // Validar valores leídos y establecer valores predeterminados si están fuera del rango
    if (humedadMax < humedadMin || humedadMax > 95) humedadMax = 95;
    if (temperaturaMax < temperaturaMin || temperaturaMax > 37) temperaturaMax = 37;
}

// Función para guardar en la EEPROM
void guardarParametrosEEPROM() {
    EEPROM.put(0, humedadMax);       // Guardar `humedadMax` en la dirección 0
    EEPROM.put(2, temperaturaMax);   // Guardar `temperaturaMax` en la dirección 2
}


// Funciones para mostrar los márgenes configurables
void mostrarMargenesHumedad() {
  //lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Humedad Maxima: ");
  lcd.print(humedadMax);
  lcd.setCursor(0, 1);
  lcd.print("Humedad Minima: ");
  lcd.print(humedadMin);
  lcd.setCursor(0, 2);
  lcd.print("Usar UP/DOWN");
  lcd.setCursor(0, 3);
  lcd.print("Select para Guardar");
}

void mostrarMargenesTemperatura() {
  //lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp Maxima: ");
  lcd.print(temperaturaMax);
  lcd.setCursor(0, 1);
  lcd.print("Temp Minima: ");
  lcd.print(temperaturaMin);
  lcd.setCursor(0, 2);
  lcd.print("Usar UP/DOWN");
  lcd.setCursor(0, 3);
  lcd.print("Select para Guardar");
}
//******************************************************FUNCIONES SUBMENU**************************************************************************//

void configurarHumedad() {
    lcd.clear();
    mostrarMargenesHumedad();  
    // Mientras el menú de configuración de humedad esté activo
    while (currentMenu == 2) {  
        // Aumentar la humedad con el botón UP
        if (digitalRead(upButton) == LOW) {
            humedadMax = humedadMax + 1;
            if (humedadMax > 95) {  // Limitar la humedad máxima a 100
                humedadMax = 95;
            }
            delay(150);  // Retraso para evitar rebotes
        }
        // Disminuir la humedad con el botón DOWN
        if (digitalRead(downButton) == LOW) {
            humedadMax = humedadMax - 1;
            if (humedadMax < humedadMin + 1) {  // Asegurar que humedadMax no sea menor que humedadMin + 1
                humedadMax = humedadMin + 1;
            }
            delay(150);  // Retraso para evitar rebotes
        }
        // Guardar el valor de humedadMax al presionar SELECT
        if (digitalRead(selectButton) == LOW) {
            guardarParametrosEEPROM();  // Guardar solo humedadMax en la EEPROM
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Humedad Guardada");
            lcd.setCursor(0, 1);
            lcd.print("Max Hume: ");
            lcd.print(humedadMax);
            delay(2500); //muestra mensaje 2 seg, luego regresa a configurar
        }
        // Comprobar si se presionó el botón BACK
        if (digitalRead(backButton) == LOW) {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Regresando..");
            lcd.setCursor(0, 1);
            lcd.print("Pulse Otra vez");
            delay(2500);  // Mostrar mensaje de regreso por 2 segundos
            currentMenu = 0;  // Volver al menú principal
            break;  // Salir del bucle y regresar al menú principal
        }
    mostrarMargenesHumedad();// Actualizar la pantalla
    }
}



void configurarTemperatura() {
    lcd.clear();
    mostrarMargenesTemperatura();  
    // Mientras el menú de configuración de humedad esté activo
    while (currentMenu == 1) {  
        // Aumentar la humedad con el botón UP
        if (digitalRead(upButton) == LOW) {
            temperaturaMax = temperaturaMax + 1;
            if (temperaturaMax > 37) {  // Limitar la humedad máxima a 100
                temperaturaMax = 37;
            }
            delay(150);  // Retraso para evitar rebotes
        }
        // Disminuir la humedad con el botón DOWN
        if (digitalRead(downButton) == LOW) {
            temperaturaMax = temperaturaMax - 1;
            if (temperaturaMax < temperaturaMin + 1) {  // Asegurar que humedadMax no sea menor que humedadMin + 1
                temperaturaMax = temperaturaMin + 1;
            }
            delay(150);  // Retraso para evitar rebotes
        }
        // Guardar el valor de humedadMax al presionar SELECT
        if (digitalRead(selectButton) == LOW) {
            guardarParametrosEEPROM();  // Guardar solo humedadMax en la EEPROM
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Temperatura Guardada");
            lcd.setCursor(0, 1);
            lcd.print("Max Temp: ");
            lcd.print(temperaturaMax);
            delay(2500);  // Mostrar mensaje de guardado por 2 segundos
            lcd.clear();
        }
        // Comprobar si se presionó el botón BACK
        if (digitalRead(backButton) == LOW) {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Regresando..");
            lcd.setCursor(0, 1);
            lcd.print("Pulse Otra vez");
            delay(2000);  // Mostrar mensaje de regreso por 2 segundos
            currentMenu = 0;  // Volver al menú principal
            break;  // Salir del bucle y regresar al menú principal
        }
    mostrarMargenesTemperatura();//actualiza pantalla
    }
}

/*
// Función para mostrar los datos actuales
void configurarTemperatura() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Configurar Tem:");
  delay(2000); // Mostrar datos por 2 segundos
  currentMenu = 0; // Volver al menú principal
  delay(200); 
}*/

// Función para iniciar incubación
void configurarDias() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Configurar Dias:");
  delay(2000); // Simula iniciar el proceso
  currentMenu = 0; // Volver al menú principal
}

// Función para mostrar el estado del sistema
void mostrarEstado() {
  lcd.clear();
  leerHumedad();
  leerTemperatura();
  leerNivelTanque();
  leerGases();
  delay(2000); // Mostrar por 2 segundos
  currentMenu = 0; // Volver al menú principal
}
/*
void mostrarEstado() {
  lcd.clear();
  while (currentMenu == 0) { // Suponiendo que el estado "1" es para mostrar estado
    leerHumedad();           // Actualiza la lectura de humedad
    leerTemperatura();       // Actualiza la lectura de temperatura
    delay(500);              // Pausa corta para evitar parpadeo excesivo en la pantalla
  }
}*/


//******************************************************FUNCIONES DEL MENU*************************************************************************//

void displayMainMenu(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(menuIndex == 0 ? "> 1.Configurar Temp" : "  1.Configurar Temp");
  lcd.setCursor(0, 1);
  lcd.print(menuIndex == 1 ? "> 2.Configurar Hume" : "  2.Configurar Hume");
  lcd.setCursor(0, 2);
  lcd.print(menuIndex == 2 ? "> 3.Configurar Dias" : "  3.Configurar Dias");
  lcd.setCursor(0, 3);
  lcd.print(menuIndex == 3 ? "> 4.Mostrar  Estado" : "  4.Mostrar  Estado");
}

// Función para manejar el menú y la selección
void handleMenu() {
  int upState = digitalRead(upButton);
  int downState = digitalRead(downButton);
  int selectState = digitalRead(selectButton);
  int backState = digitalRead(backButton);

  if (upState == LOW && lastUpState == HIGH) {
    menuIndex = (menuIndex - 1 + 4) % 4; // Mover hacia arriba
    displayMainMenu();
  }

  if (downState == LOW && lastDownState == HIGH) {
    menuIndex = (menuIndex + 1) % 4; // Mover hacia abajo
    displayMainMenu();
  }

  if (selectState == LOW && lastSelectState == HIGH) {
    switch (menuIndex) {
      case 0:
        currentMenu = 1;
        configurarTemperatura();
        break;
      case 1:
        currentMenu = 2;
        configurarHumedad();
        break;
      case 2:
        currentMenu = 3;
        configurarDias();
        break;
      case 3:
        currentMenu = 4;
        mostrarEstado();
        break;
    }
  }

  if (backState == LOW && lastBackState == HIGH) {
    currentMenu = 0; // Volver al menú principal
    displayMainMenu();
  }

  lastUpState = upState;
  lastDownState = downState;
  lastSelectState = selectState;
  lastBackState = backState;
}

// Función para mostrar el mensaje de bienvenida
void mostrarBienvenida() {
  lcd.setCursor(0, 0);
  lcd.print("|------------------|");
  lcd.setCursor(0, 1);
  lcd.print("Iniciando Incubadora");
  lcd.setCursor(0, 2);
  lcd.print("|    Bienvenido    |");
  lcd.setCursor(0, 3);
  lcd.print("|------------------|");
  delay(3500);
  lcd.clear();
}

void iniciarBotones(){
  pinMode(upButton, INPUT);
  pinMode(downButton, INPUT);
  pinMode(selectButton, INPUT_PULLUP);
  pinMode(backButton, INPUT_PULLUP);
}


//******************************************************FUNCIONES DE CONTROL***********************************************************************//

void controlarHumidificador() {
    //leerHumedad();
    humedad = dht.readHumidity();

    // Si la humedad es mayor a 85%, se apaga el humidificador
    if (humedad > humedadMax) {
        digitalWrite(relePin, HIGH); // Relé apagado
        Serial.println("Humidificador Apagado");
    }
    // Si la humedad es menor a 70%, se enciende el humidificador
    else if (humedad < humedadMin) {
        digitalWrite(relePin, LOW); // Relé encendido
        Serial.println("Humidificador Encendido");
    }
    if (humedad > 90) {        
        activarAlarma();
        Serial.println("¡Alerta! Humedad crítica");
    } else {
        desactivarAlarma();
  }
}

void ControlarTemperatura() {

    if (temperatura > temperaturaMax) {
        activarAlarma();  // Activa la alarma si la temperatura es alta
        Serial.println("¡Alerta! Temperatura crítica");
        desactivarVentiladorCalefaccion(); // Apaga el ventilador si supera 30 °C
        Serial.println("Ventilador Apagado");
    } else {
        desactivarAlarma();
        Serial.println("Ventilador Encendido");
        activarVentiladorCalefaccion(); // Enciende el ventilador si la temperatura está bajo 30 °C
    }
}


/*
void comenzarProgramaHumidificador(){

  iniciarSistemaHumidificador();
  //controlarHumidificadorAntes19();

}*/
