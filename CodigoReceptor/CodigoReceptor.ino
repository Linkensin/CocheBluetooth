
#include <SoftwareSerial.h>

#include "Constantes.h"
#include "Debug.h"

String DatosRecibidos;
char Orden;
int ValorBoton;

SoftwareSerial BluetoothReceptor = SoftwareSerial(pinRx, pinTx);

void setup() {
  Serial.begin(9600); //Inicio monitor serial
  pinMode(pinRx, INPUT);
  pinMode(pinTx, OUTPUT);

  BluetoothReceptor.begin(9600);

  //FuncActivarPinesLedsDeDebug();
}

void loop() {
  if(BluetoothReceptor.available()){
    DatosRecibidos = BluetoothReceptor.readStringUntil('\n');
    sscanf(DatosRecibidos.c_str(), "%c,%d", &Orden, &ValorBoton);

    //FuncEncenderLedsDebug(Orden, ValorBoton);
    //FuncMostrarDatosRecibidos(Orden, ValorBoton);
    ;

  }
}
