
#include <SoftwareSerial.h>

#include "Constantes.h"
#include "Debug.h"

SoftwareSerial BluetoothTransmisor = SoftwareSerial(pinRx, pinTx); //Rx = 10 + Tx = 11

int ValorX, ValorY;
bool ValorBoton;
char Direccion;
String Mensaje, MesanjeAnterior;

char FuncCalcularDireccion(int EntradaX, int EntradaY){
  if(EntradaX < EstandarDeEntrada-DiferenciaMinima){ // X mas pequeño que 300 = Izuierda
    return 'L';
  }else if(EntradaX > EstandarDeEntrada+DiferenciaMinima){ // X mas grande que 700 = Derecha
    return 'R';
  }else if(EntradaY < EstandarDeEntrada-DiferenciaMinima){ // Y mas pequeño que 300 = Atras
    return 'B';
  }else if(EntradaY > EstandarDeEntrada+DiferenciaMinima){ // Y mas grande que 700 = Adelante
    return 'F';
  }else{ //Si no hay movimiento entonces devuelve N = Nada
    return 'N';
  }
}

void setup() {
  Serial.begin(9600); //Inicio monitor serial a 9600 baudios
  pinMode(pinJoystickX, INPUT);
  pinMode(pinJoystickY, INPUT);
  pinMode(pinJoystickPulsador, INPUT_PULLUP); //Para activar resistencia PULLUP

  pinMode(pinRx, INPUT);
  pinMode(pinTx, OUTPUT);

  BluetoothTransmisor.begin(9600); 
}

void loop() {
  ValorX = analogRead(pinJoystickX);
  delay(100); //Necessitas un tiempo de demora entre lectura analogica
  ValorY = analogRead(pinJoystickY);

  ValorBoton = digitalRead(pinJoystickPulsador);

  //FuncMostrarDatosMonitorSerial(ValorX, ValorY, ValorBoton);   //Para mostrar los datos por el monitor Serial

  Direccion = FuncCalcularDireccion(ValorX, ValorY);
  /* //Para printear directamente la informacion al monitor serial
  Serial.print(!ValorBoton);
  Serial.print(" | ");
  Serial.println(Direccion);
  */

  MesanjeAnterior = Mensaje;

  Mensaje = String(Direccion) + "," + String(!ValorBoton) + "\n"; //Tranformo las variables en formato cadena de letras y los concateno

  if(Mensaje != MesanjeAnterior){ //Asi solo se envian mensajes que no sean iguales, para poder transmitir de manera mas eficiente
    BluetoothTransmisor.print(Mensaje); //Enviar el mensaje al modulo de bluetooth
    //Serial.println(Mensaje);
  }
}
