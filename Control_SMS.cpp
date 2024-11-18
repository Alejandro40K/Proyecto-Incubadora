

//////////////////////////////////////////////////////////////////
// Materia:  Seminario de Sensores y acondicionamiento de señales
// Proyecto: Incubadora: Control de Sistema con RTC
// Profesor: CARLOS ALBERTO SANCHEZ ROMERO
// Alumno:   Alejando Orozco Romo
// Codigo:   218171511
// Archivo:  Control_Sistema.cpp
// Fecha de edicion: 21/10/2024

//////////////////////////////////////////////////////////////////

/*
//BIBLIOTECAS 
#include "Control_Sistema.h"
#include "Control_Gases.h"
#include "Control_Motor.h"
#include "Control_humedad.h"
#include "Control_Temperatura.h"
#include "LCD.h"
#include "Control_Ventilacion.h"

bool cicloActivo = false; 
RTC_DS1307 rtc;
DateTime fechaInicioIncubacion;

// Variable para el día de incubación
int diaIncubacion = 0;

// Inicialización del RTC y configuración de la fecha de inicio de incubación
void IniciarRTC() {
  if (!rtc.begin()) {
    Serial.println("No se puede encontrar el RTC");
    while (1);
  }

  if (!rtc.isrunning()) {
    Serial.println("El RTC ha perdido el poder, ajustando el reloj...");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));  // Ajusta a la fecha y hora actual de la compilación
  }

  //fechaInicioIncubacion = DateTime(2024, 11, 11, 0, 0, 0);
}


// Función para calcular cuántos días han pasado desde el inicio de la incubación
int obtenerDiaIncubacion() {
  DateTime ahora = rtc.now();  // Obtiene la fecha y hora actual del RTC
  TimeSpan duracion = ahora - fechaInicioIncubacion;  // Calcula la diferencia de tiempo

  return duracion.days();  // Devuelve el número de días transcurridos
}

//FUNCION NUEVA, HACER UN TEST DE CONTROL
void actualizarEstadoIncubacion() {
    diaIncubacion = obtenerDiaIncubacion();

    if (diaIncubacion <= 18) {
        //controlarHumidificadorAntes19();
        ControlarTemperaturaAntes19();
        activarVentiladorEntrada();
        activarVentiladorSalida();

    } else if (diaIncubacion > 18 && diaIncubacion <= 21) {
        //controlarHumidificadorDespues19();
        ControlarTemperaturaDespues19();
        activarVentiladorEntrada();
        activarVentiladorSalida();
    } else {
        // Ciclo completado después de 21 días
        desactivarVentiladorCalefaccion();
        desactivarVentiladorSalida();
        desactivarVentiladorEntrada();

        lcd.clear();
        lcd.print("Ciclo finalizado");
        cicloActivo = false;
    }
}

void leerRTC(){
  // Obtenemos el día actual de incubación
    int diasTranscurridos = obtenerDiaIncubacion();

    // Mostramos en el monitor serial (opcional)
    Serial.print("Dias transcurridos desde el inicio de la incubacion: ");
    Serial.println(diasTranscurridos);

    // Mostramos en la pantalla LCD
    lcd.setCursor(0, 1);
    lcd.print("Dias: ");
    lcd.print(diasTranscurridos);
}

void mostrarInformacion() {
    leerRTC();
    leerHumedad();
    leerTemperatura();
    leerNivelTanque();
    leerGases();
}


void comenzarSistema(){
  actualizarEstadoIncubacion();
  mostrarInformacion();
  //iniciarSistemaMotor();  
}


void iniciarComponentes() {
    iniciarSistemaHumidificador();
    IniciarSistemaTemperatura();
    iniciarLCD();
    IniciarRTC();
    //inicializarMotor(); 
}

*/
