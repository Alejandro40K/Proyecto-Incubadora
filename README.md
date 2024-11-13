/*
 * Nombre del archivo: sensorTemperatura.h
 * Descripción: Este archivo contiene la declaración de la clase SensorTemperatura
 *              y las funciones necesarias para leer los datos del sensor de temperatura.
 *
 * Proyecto: Sistema de Control de Incubadora de Huevos
 * Autor: Alejandro Orozco Romo
 * Fecha de creación: 2024-11-02
 * Última modificación: 2024-11-02
 *
 * Dependencias:
 *    - Librería DHT (para sensores de temperatura y humedad DHT11, DHT22)
 *
 * Notas:
 *    - Este archivo define los métodos para inicializar y leer el sensor de temperatura.
 *    - Asegúrate de conectar correctamente el sensor al Arduino antes de usar este código.
 *    - Configurar las variables de pin en el archivo de configuración principal.
 *
 * Historial de cambios:
 *    - 2024-11-02: Creación del archivo y primera implementación de la clase SensorTemperatura.
 *
 * Licencia:
 *    - Este código es propiedad de Alejandro Orozco Romo y puede ser modificado y distribuido 
 *      bajo los términos de la licencia MIT.
 */


# Proyecto-Incubadora

NOTAS:

1) Se necesita comenzar a documentar el codigo, describiendo las funciones pertenecientes a cada modulo
   del sistema. 
2) Se deberá depurar el codigo para eliminar numeros mágicos y asignar reglas de buena codificacion para los 
   nombres de las variables de cada funcion. 
3) Modificar el diagrama de flujo para añadir o eliminar las nuevas funciones que se van a estar agregando.
4) Usar una metodologia TOP-DOWN descrita en el documento para espesificar el proceso de desarrollo, las partes que se 
   necesitan.
5) Preguntar cual es el formato de un buen reporte de desarrollo para un proyecto. 

PRIORIDADES:

1) Añadir sensor de gaz a la incubadora, con alarma, solo es necesario que muestre informacion
2) Adecuar el motor a pasos para que funcione despues del 13 dia, y que mueva los huevos cada 6 horas
3) Modificar el RTC para que tenga las siguentes funciones: 
    a) Boton de iniciar sistema: en este boton se reiniciara el sistema con un ciclo de 21 dias.
    b) Mostrar datos: Mostrara los datos de temperatura, dia, humedad y los gases 
4) MENU: agregar el menu con 2 botones o un joistik
5) Agregar el control de la tarjeta sim para enviar mensajes al celular. 
6) cabiar los encabesados de todos los archivos por el que esta hasta arriba de este readme.


PENDIENTE 11/11/24

ARCHIVO: Main.cpp

1) Mejorar la implementacion del control temperatura, posiblemente implementar el control del ventilador calefacciomn directamente en el control 
temoeratura a la misma forma que el humidifiador. 
eliminr redundamcia en funciones inicializar