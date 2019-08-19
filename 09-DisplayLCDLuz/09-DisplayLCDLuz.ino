/** @file    08-PantallaLCD.ino
 *  @author  Jorge Villalobos Carvajal (jorgemvc@gmail.com)
 *  @date    19.Ago.2019  
 *  @version 1.0 
 *  
 *  @brief   Lectura de un sensor de luminosidad con
 *           pantalla LCD.
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
  luzPin = A2,
  sensorValue;
  
void setup() {
  // Se abre el puerto serial
  Serial.begin(9600);
  
  // Se establecen las columnas y filas de la pantalla
  lcd.begin(16, 2);
}  // setup

void loop() {
  // Realiza la lectura del sensor
  sensorValue = analogRead(luzPin);

  int luz = map(sensorValue, 0, 1023, 0, 100);

  lcd.clear();
  lcd.print("Valor : ");
  lcd.print(sensorValue);

  lcd.setCursor(0, 2);
  lcd.print("Porc. : ");
  lcd.print(luz);
  lcd.print(" %");
  
  Serial.print("Valor medido: ");
  Serial.print(sensorValue);
  Serial.print(" - Porc: ");
  Serial.println(luz);

  delay(500);
}  // loop
