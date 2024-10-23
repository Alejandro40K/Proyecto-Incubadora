//////////////////////////////////////////////////////////////////
// Materia:  Seminario de Sensores y acondicionamiento de señales
// Proyecto: Incubadora: Control de Sistema con RTC
// Profesor: CARLOS ALBERTO SANCHEZ ROMERO
// Alumno:   Alejando Orozco Romo
// Codigo:   218171511
// Archivo:  Control_Sistema.cpp
// Fecha de edicion: 21/10/2024
//////////////////////////////////////////////////////////////////

//BIBLIOTECAS 
#include "Control_Sistema.h"

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
  // Configura la fecha de inicio de la incubación
  // Ejemplo: 1 de octubre de 2024
  fechaInicioIncubacion = DateTime(2024, 10, 21, 0, 0, 0);
  iniciarSistemaHumidificador();
  iniciarLCD();

}

/* SE USARA CUANDO SE TENGAN TODOS LOS DEMAS SENSORES Y MOTORES 
void iniciarComponentes() {
    iniciarSistemaHumidificador(); // Inicializa el DHT11, el relé, la alarma y el LCD
    IniciarRTC(); // Inicializa el RTC
}*/

// Función para calcular cuántos días han pasado desde el inicio de la incubación
int obtenerDiaIncubacion() {
  DateTime ahora = rtc.now();  // Obtiene la fecha y hora actual del RTC
  TimeSpan duracion = ahora - fechaInicioIncubacion;  // Calcula la diferencia de tiempo

  return duracion.days();  // Devuelve el número de días transcurridos
}



// Función que actualiza el estado de incubación (temperatura, alarma, etc.)
void actualizarEstadoIncubacion() {
    // Primero obtenemos el día actual de incubación
    diaIncubacion = obtenerDiaIncubacion();

    // Controlar la humedad dependiendo del día de incubación
    if (diaIncubacion > 18) {
        controlarHumidificadorDespues19();  // Control específico después del día 18
    } else {
        controlarHumidificadorAntes19();  // Control normal antes del día 18
    }
}


void mostrarInformacion() {
    // Obtenemos el día actual de incubación
    int diasTranscurridos = obtenerDiaIncubacion();

    // Mostramos en el monitor serial (opcional)
    Serial.print("Dias transcurridos desde el inicio de la incubacion: ");
    Serial.println(diasTranscurridos);

    // Mostramos en la pantalla LCD
    //lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Dias: ");
    lcd.print(diasTranscurridos);

    // Llamamos a la funcion mostrarHumedad para mostrar la humedad
    mostrarHumedad();  // Esto mostrará la humedad en la segunda línea
}


void comenzarSistema(){
  comenzarProgramaHumidificador();
  actualizarEstadoIncubacion();
  mostrarInformacion(); 
}