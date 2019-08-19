/** @file    10-PantallaLCDLuzTemp.ino
 *  @author  Jorge Villalobos Carvajal (jorgemvc@gmail.com)
 *  @date    19.Ago.2019  
 *  @version 1.0 
 *  
 *  @brief   Lectura de un sensor de luminosidad con
 *           pantalla LCD, un sensor de luz y de temperatura.
 *
 *  @licence  MIT License
 */
// Biblioteca para el LCD
#include <LiquidCrystal.h>

// Variables para la conexión del LCD
const int 
  rs = 8, en = 9, 
  d4 = 4, d5 = 5, 
  d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int
  tempPin = A1,
  valorSensorTemp,
  luzPin = A2,
  valorSensorLuz;

byte customChar[] = {
  B00100,
  B01010,
  B01010,
  B00100,
  B00000,
  B00000,
  B00000,
  B00000
};
  
void setup() {
  // Se abre el puerto serial
  Serial.begin(9600);
  
  // Se establecen las columnas y filas de la pantalla
  lcd.begin(16, 2);
  lcd.createChar(0, customChar);
}  // setup

void loop() {
  // Realiza la lectura del sensor
  valorSensorLuz = analogRead(luzPin);
  int luz = map(valorSensorLuz, 0, 1023, 0, 100);

  valorSensorTemp = analogRead(tempPin);

  // Voltaje obtenido de los 5V posibles
  float voltage = (valorSensorTemp / 1024.0) * 5.0;

  // La base del sensor está desplazada 
  // 500mV (-50 grados)
  // Cada 10mV se incrementa 1 grado celsius
  float temp = (voltage - 0.5) * 100;

  lcd.clear();
  lcd.print("Luz : ");
  lcd.print(valorSensorLuz);

  lcd.print(" - ");
  lcd.print(luz);
  lcd.print("%");

  lcd.setCursor(0,1);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" ");
  lcd.write(byte(0));
  lcd.print("C");
  
  Serial.print("Valor medido: ");
  Serial.print(valorSensorLuz);
  Serial.print(" - Porc: ");
  Serial.println(luz);

  delay(500);
}  // loop
