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
#include "Control_Ventilacion.h"
#include "Control_Sistema.h"
#include "Control_humedad.h"
#include "Control_Alarma.h"
#include "Control_Gases.h"
#include "LCD.h"

//***********************************************************DEFINIMOS OBJETOS*********************************************************************//

//Temperatura
OneWire ourWire(2);           
DallasTemperature sensors(&ourWire);
//RTC DS1307
RTC_DS1307 rtc;
DateTime fechaFinIncubacion;
DateTime fechaInicioIncubacion; // Declara fechaInicioIncubacion

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
int humedadMin = 50;  // Valor por defecto mínimo de humedad
int humedadMax = 95;  // Valor por defecto máximo de humedad
// Variables de temperatura
//float temperatura = 0;
int temperaturaMin = 24;
int temperaturaMax = 37;
float temp =0;
// Variables RTC dias 
const int EEPROM_DAYS_ADDR = 16;
const int EEPROM_END_DATE_ADDR = 20;
const int EEPROM_START_DATE_ADDR = 24;
int diaIncubacion = 0;
int diasMaximos = 37;
int diasMinimos = 17;
bool cicloActivo = false;

//************************************************FUNCIONES PARA INICIAR SISTEMA*******************************************************************//
void iniciarSistemaTotal() {
    iniciarBotones();
    leerParametrosEEPROM();
    iniciarSistemaHumidificador();
    IniciarSistemaTemperatura();
    iniciarVentiladores();
    IniciarRTC();
    cargarFechaInicioEEPROM();
    cargarFechaFinEEPROM();

    // Comprobar si hay datos válidos para el ciclo activo
    if (!cicloActivo) {  
        if (fechaInicioIncubacion.unixtime() == 0 || fechaFinIncubacion.unixtime() == 0) {
            iniciarCicloIncubacion();  // Solo inicia si no hay fechas válidas
        } else {
            cicloActivo = true;  // Marca el ciclo como activo si hay fechas válidas
        }
    }

    mostrarBienvenida();
    displayMainMenu();
}

//se llama en el void
void ComenzarSistemaTotal(){
  handleMenu();  // Maneja las interacciones del menú
  if (cicloActivo) {
    // Si el ciclo está activo, actualiza el estado de la incubación
    actualizarEstadoIncubacion();
  } else {
    // Si el ciclo ha terminado, muestra un mensaje en el LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Ciclo Terminado");
    lcd.setCursor(0, 1);
    lcd.print("Esperando reinicio");
    // Aquí podrías agregar la lógica para reiniciar el ciclo si es necesario. 
  }
}

//******************************************************FUNCIONES EEPROM***************************************************************************//

// Función para leer en la EEPROM
void leerParametrosEEPROM() {
    // Leer `humedadMax` desde la dirección 0
    EEPROM.get(0, humedadMax);
    // Leer `temperaturaMax` desde la dirección 2
    EEPROM.get(2, temperaturaMax);
    // Leer `diasMaximos` desde la dirección 16
    EEPROM.get(EEPROM_DAYS_ADDR,diasMaximos);
    EEPROM.get(EEPROM_DAYS_ADDR + sizeof(diasMaximos), diaIncubacion);

    // Validar valores leídos y establecer valores predeterminados si están fuera del rango
    if (humedadMax < humedadMin || humedadMax > 95) humedadMax = 95;
    if (temperaturaMax < temperaturaMin || temperaturaMax > 37) temperaturaMax = 37;
    if (diasMaximos < diasMinimos || diasMaximos > 37) diasMaximos = 37;
}

// Función para guardar en la EEPROM
void guardarParametrosEEPROM() {
    EEPROM.put(0, humedadMax);       // Guardar `humedadMax` en la dirección 0
    EEPROM.put(2, temperaturaMax);   // Guardar `temperaturaMax` en la dirección 2
    EEPROM.put(EEPROM_DAYS_ADDR, diasMaximos);   // Guardar `diaIncubacion` en la dirección 16
    EEPROM.put(EEPROM_DAYS_ADDR + sizeof(diasMaximos), diaIncubacion);
}

void guardarFechaFinEEPROM() {
  EEPROM.put(EEPROM_END_DATE_ADDR, fechaFinIncubacion.unixtime());
}

void cargarFechaFinEEPROM() {
  uint32_t fechaUnix;
  EEPROM.get(EEPROM_END_DATE_ADDR, fechaUnix);  // Lee la fecha en formato Unix de la EEPROM
  fechaFinIncubacion = DateTime(fechaUnix);  // Convierte el valor a un objeto DateTime
}

// Función para guardar la fecha de inicio en la EEPROM
void guardarFechaInicioEEPROM() {
  uint32_t fechaInicio = fechaInicioIncubacion.unixtime();
  EEPROM.put(EEPROM_START_DATE_ADDR, fechaInicio);
  Serial.print("Fecha de inicio guardada en EEPROM: ");
  Serial.println(fechaInicio);
}

void cargarFechaInicioEEPROM() {
  uint32_t fechaUnix;
  EEPROM.get(EEPROM_START_DATE_ADDR, fechaUnix);
  if (fechaUnix == 0) {  // Verifica si la fecha leída es 0 (valor no inicializado)
    // Establecer una fecha predeterminada si es el primer inicio
    fechaInicioIncubacion = rtc.now();
  } else {
    fechaInicioIncubacion = DateTime(fechaUnix);
  }
  Serial.print("Fecha de inicio de la incubación: ");
  Serial.println(fechaInicioIncubacion.timestamp());
}

//******************************************************FUNCIONES RTC DIAS*************************************************************************//

void IniciarRTC() {
  if (!rtc.begin()) {
    Serial.println("No se puede encontrar el RTC");
    while (1);
  }
  if (!rtc.isrunning()) {
    Serial.println("El RTC ha perdido el poder, ajustando el reloj...");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));  // Ajusta a la fecha y hora actual de la compilación
  }
}

// Función para iniciar el ciclo de incubación
void iniciarCicloIncubacion() {
  DateTime fechaActual = rtc.now();
  fechaInicioIncubacion = fechaActual;  // Guarda la fecha de inicio
  fechaFinIncubacion = fechaActual + TimeSpan(diasMaximos, 0, 0, 0);  // Calcula la fecha final sumando los días máximos
  guardarFechaFinEEPROM();  // Guarda la fecha de fin en la EEPROM
  guardarFechaInicioEEPROM();  // Guarda la fecha de inicio en la EEPROM
  cicloActivo = true;  // Marca el ciclo como activo
  diaIncubacion = 1;  // Inicia el contador de días de incubación
}

// Nueva función para calcular los días transcurridos
int calcularDiasTranscurridos() {
  DateTime fechaActual = rtc.now();
  TimeSpan diferencia = fechaActual - fechaInicioIncubacion;
  return diferencia.days();  // Devuelve la diferencia en días
}

// Función para leer el RTC y mostrar los días transcurridos
void leerRTC() {
  int diasTranscurridos = calcularDiasTranscurridos();  // Calcula los días desde el inicio

  // Muestra en el monitor serial
  Serial.print("Días transcurridos desde el inicio de la incubación: ");
  Serial.println(diasTranscurridos);

  // Muestra en la pantalla LCD
  lcd.setCursor(0, 2);
  lcd.print("Dias: ");
  lcd.print(diasTranscurridos);
}

void actualizarEstadoIncubacion() {
    diaIncubacion = calcularDiasTranscurridos();

    if (diaIncubacion <= diasMaximos - 3) {
        // Controla solo la temperatura en los primeros días
        controlarHumidificador();
        ControlarTemperatura();
        activarVentiladorEntrada();
        activarVentiladorSalida();
    } 
    else if (diaIncubacion > 18 && diaIncubacion <= diasMaximos) { 
        // Controla tanto temperatura como humedad en los días siguientes
        controlarHumidificador(); 
        ControlarTemperatura(); 
        activarVentiladorEntrada();
        activarVentiladorSalida();
    } 
    else {
        desactivarVentiladorSalida();
        desactivarVentiladorEntrada();
        lcd.clear();
        lcd.print("Ciclo finalizado");
        cicloActivo = false;
    }
}

//******************************************************FUNCIONES SUBMENU**************************************************************************//

// Funciones para mostrar los márgenes configurables
void mostrarMargenesHumedad() {
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

void mostrarMargenesDias() {
  lcd.setCursor(0, 0);
  lcd.print("Dias Incubacion: ");
  lcd.print(diasMaximos);
  lcd.setCursor(0, 1);
  lcd.print("Dias Minimos: ");
  lcd.print(diasMinimos);
  lcd.setCursor(0, 2);
  lcd.print("Usar UP/DOWN");
  lcd.setCursor(0, 3);
  lcd.print("Select para Guardar");
}

void configurarDias() {
    lcd.clear();
    mostrarMargenesDias();  
    // Mientras el menú de configuración de humedad esté activo
    while (currentMenu == 3) {  
        // Aumentar la humedad con el botón UP
        if (digitalRead(upButton) == LOW) {
            diasMaximos = diasMaximos + 1;
            if (diasMaximos > 37) {  // Limitar la humedad máxima a 100
                diasMaximos = 37;
            }
            delay(150);  // Retraso para evitar rebotes
        }
        // Disminuir la humedad con el botón DOWN
        if (digitalRead(downButton) == LOW) {
            diasMaximos = diasMaximos - 1;
            if (diasMaximos < diasMinimos + 1) {  // Asegurar que humedadMax no sea menor que humedadMin + 1
                diasMaximos = diasMinimos + 1;
            }
            delay(150);  // Retraso para evitar rebotes
        }
        // Guardar el valor de humedadMax al presionar SELECT
        if (digitalRead(selectButton) == LOW) {
            guardarParametrosEEPROM();  // Guardar solo humedadMax en la EEPROM
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Tiempo de incubacion");
            lcd.setCursor(0, 1);
            lcd.print("Guardado con exito!");
            lcd.setCursor(0, 2);
            lcd.print("Duracion: ");
            lcd.print(diasMaximos);
            lcd.setCursor(14, 2);
            lcd.print("Dias");
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
    mostrarMargenesDias();//actualiza pantalla
    }
}

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

// Función para mostrar el estado del sistema
void mostrarEstado() {
  lcd.clear();
  leerHumedad();
  lcd.setCursor(0, 1);
  lcd.print("Ta:");
  lcd.print(temp);
  lcd.print("C");
  leerNivelTanque();
  leerGases();
  leerRTC();
  delay(2000); // Mostrar por 2 segundos
  currentMenu = 0; // Volver al menú principal
}

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

//******************************************************FUNCIONES DE CONTROL HUMEDAD***************************************************************//

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

//**********************************************************FUNCIONES CONTROL TEMPERATURA**********************************************************//

void IniciarSistemaTemperatura() {
    delay(1000);
    sensors.begin();
    pinMode(VentiladorCalefaccion, OUTPUT);
    digitalWrite(VentiladorCalefaccion, HIGH); // Relé apagado
}

// Leer temperatura
float leerTemperatura() {
    sensors.requestTemperatures();
    temp = sensors.getTempCByIndex(0);
    return temp;
}

// Control de la temperatura
void ControlarTemperatura() {
  leerTemperatura();
    if (temp > temperaturaMax) {
        digitalWrite(VentiladorCalefaccion, HIGH); // Apaga el ventilador
        //Serial.println("Ventilador Apagado");
    }else{
        digitalWrite(VentiladorCalefaccion, LOW); // Enciende el ventilador
        //Serial.println("Ventilador Encendido");
    }
    if (temp > 38) {        
        activarAlarma();
        Serial.println("¡Alerta! Temperatura crítica");
    } else {
        desactivarAlarma();
    }
}
