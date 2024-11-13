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

//Función de prueba
/*
void empezarVentilador(){
    activarVentiladorEntrada();  
    delay(2000);
    desactivarVentiladorEntrada(); 
}*/