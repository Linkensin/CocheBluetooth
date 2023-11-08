
void FuncMostrarDatosMonitorSerial(int DatosX, int DatosY, bool EstadoBoton){
  //mostrar valores por serial
  Serial.print("X:" );
  Serial.print(DatosX);
  Serial.print(" | Y: ");
  Serial.print(DatosY);
  Serial.print(" | Pulsador: ");
  Serial.println(!EstadoBoton);
  delay(10);
}