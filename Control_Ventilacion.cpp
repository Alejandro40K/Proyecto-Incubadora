//////////////////////////////////////////////////////////////////
// Materia:  Seminario de Sensores y acondicionamiento de señales
// Proyecto: Incubadora: Sitema de control de Ventilacion
// Profesor: CARLOS ALBERTO SANCHEZ ROMERO
// Alumno:   Alejando Orozco Romo
// Codigo:   218171511
// Archivo:  Control_Ventilacion.cpp
// Fecha de edicion: 17/10/2024
//////////////////////////////////////////////////////////////////

// BIBLIOTECAS 
#include "Control_Ventilacion.h"

void iniciarVentiladores() {
    pinMode(VentiladorCalefaccion, OUTPUT);
    digitalWrite(VentiladorCalefaccion, HIGH); // Relé apagado

    pinMode(VentiladorEntrada, OUTPUT);
    digitalWrite(VentiladorEntrada, HIGH); // Relé apagado

    pinMode(VentiladorSalida, OUTPUT);
    digitalWrite(VentiladorSalida, HIGH); // Relé apagado
}

//VENTILADOR DE ENTRADA
void activarVentiladorEntrada(){
    digitalWrite(VentiladorEntrada, LOW);  // Activa el ventilador
}
void desactivarVentiladorEntrada(){
    digitalWrite(VentiladorEntrada, HIGH); // Desactiva el ventilador
}

//VENTILADOR DE SALIDA
void activarVentiladorSalida(){
    digitalWrite(VentiladorSalida, LOW);  // Activa el ventilador
}
void desactivarVentiladorSalida(){ // Corrección aquí
    digitalWrite(VentiladorSalida, HIGH);  // Desactiva el ventilador
}

//VENTILADOR DE CALEFACCION 
void activarVentiladorCalefaccion(){
    digitalWrite(VentiladorCalefaccion, LOW);  // Activa el ventilador de calefacción
}
void desactivarVentiladorCalefaccion(){
    digitalWrite(VentiladorCalefaccion, HIGH);  // Desactiva el ventilador de calefacción
}


/* Función de prueba
void empezarVentilador(){
    activarVentiladorEntrada();  
    delay(2000);
    desactivarVentiladorEntrada(); 
}*/