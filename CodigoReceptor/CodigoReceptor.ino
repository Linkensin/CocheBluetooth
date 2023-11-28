
#include <SoftwareSerial.h>

#include "Constantes.h"
#include "Debug.h"

String DatosRecibidos;
char Orden;
int ValorBoton;

SoftwareSerial BluetoothReceptor = SoftwareSerial(pinRx, pinTx);

void FuncEjecutarOrden(char Intruccion){
  switch(Intruccion){
    case 'F': //Adelante
    //Motor 1
    digitalWrite(JumperA, MaxSpeed);
    digitalWrite(EntradaUnoUno, HIGH);
    digitalWrite(EntradaUnoDos, LOW);
    //Motor 2
    digitalWrite(JumperB, MaxSpeed);
    digitalWrite(EntradaDosUno, HIGH);
    digitalWrite(EntradaDosDos, LOW);
    break;

    case 'B': //Atras
    //Motor 1
    digitalWrite(JumperA, MaxSpeed);
    digitalWrite(EntradaUnoUno, LOW);
    digitalWrite(EntradaUnoDos, HIGH);
    //Motor 2
    digitalWrite(JumperB, MaxSpeed);
    digitalWrite(EntradaDosUno, LOW);
    digitalWrite(EntradaDosDos, HIGH);
    break;

    case 'R': //Derecha
    //Motor 1
    digitalWrite(JumperA, MidSpeed);
    digitalWrite(EntradaUnoUno, HIGH);
    digitalWrite(EntradaUnoDos, LOW);
    //Motor 2
    digitalWrite(JumperB, SlowSpeed);
    digitalWrite(EntradaDosUno, LOW);
    digitalWrite(EntradaDosDos, HIGH);
    break;

    case 'L': //Izquierda
    //Motor 1
    digitalWrite(JumperA, SlowSpeed);
    digitalWrite(EntradaUnoUno, LOW);
    digitalWrite(EntradaUnoDos, HIGH);
    //Motor 2
    digitalWrite(JumperB, MidSpeed);
    digitalWrite(EntradaDosUno, HIGH);
    digitalWrite(EntradaDosDos, LOW);
    break;

    case 'N': //Parado
    //Motor 1
    digitalWrite(JumperA, NoSpeed);
    digitalWrite(EntradaUnoUno, LOW);
    digitalWrite(EntradaUnoDos, LOW);
    //Motor 2
    digitalWrite(JumperB, NoSpeed);
    digitalWrite(EntradaDosUno, LOW);
    digitalWrite(EntradaDosDos, LOW);
    break;
  }
}

void setup() {
  Serial.begin(9600); //Inicio monitor serial
  pinMode(pinRx, INPUT);
  pinMode(pinTx, OUTPUT);

  BluetoothReceptor.begin(9600);

  //Declarar Salida de datos para los controles del coche
  pinMode(JumperA, OUTPUT);
  pinMode(EntradaUnoUno, OUTPUT);
  pinMode(EntradaUnoDos, OUTPUT);
  pinMode(JumperB, OUTPUT);
  pinMode(EntradaDosUno, OUTPUT);
  pinMode(EntradaDosDos, OUTPUT);

  //FuncActivarPinesLedsDeDebug();
}

void loop() {
  if(BluetoothReceptor.available()){
    DatosRecibidos = BluetoothReceptor.readStringUntil('\n');
    sscanf(DatosRecibidos.c_str(), "%c,%d", &Orden, &ValorBoton);
 
    //FuncEncenderLedsDebug(Orden, ValorBoton);
    //FuncMostrarDatosRecibidos(Orden, ValorBoton);
    FuncEjecutarOrden(Orden);

  }
}
