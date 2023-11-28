
#include "Constantes.h"

void FuncActivarPinesLedsDeDebug(){
  pinMode(pinLedDelante, OUTPUT);
  pinMode(pinLedAtras, OUTPUT);
  pinMode(pinLedIzquierda, OUTPUT);
  pinMode(pinLedDerecha, OUTPUT);
}

void FuncEncenderLedsDebug(char Orden, int EstadoBoton){
  switch(Orden){
    case 'F': 
    digitalWrite(pinLedDelante, HIGH);
    digitalWrite(pinLedAtras, LOW);
    digitalWrite(pinLedIzquierda, LOW);
    digitalWrite(pinLedDerecha, LOW);
    break;
    case 'B': 
    digitalWrite(pinLedDelante, LOW);
    digitalWrite(pinLedAtras, HIGH);
    digitalWrite(pinLedIzquierda, LOW);
    digitalWrite(pinLedDerecha, LOW);
    break;
    case 'L': 
    digitalWrite(pinLedDelante, LOW);
    digitalWrite(pinLedAtras, LOW);
    digitalWrite(pinLedIzquierda, HIGH);
    digitalWrite(pinLedDerecha, LOW);
    break;
    case 'R': 
    digitalWrite(pinLedDelante, LOW);
    digitalWrite(pinLedAtras, LOW);
    digitalWrite(pinLedIzquierda, LOW);
    digitalWrite(pinLedDerecha, HIGH);
    break;
    default: 
    digitalWrite(pinLedDelante, LOW);
    digitalWrite(pinLedAtras, LOW);
    digitalWrite(pinLedIzquierda, LOW);
    digitalWrite(pinLedDerecha, LOW);
    break;
  }
  if(EstadoBoton == HIGH){
    digitalWrite(pinLedEstadoBoton, HIGH);
  }else{
    digitalWrite(pinLedEstadoBoton, LOW);
  }
}

void FuncMostrarDatosRecibidos(char OrdenAEjecutar, int EstadoBoton){
  Serial.print(OrdenAEjecutar);
  Serial.print(" | ");
  Serial.println(EstadoBoton);
}
