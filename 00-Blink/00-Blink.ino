/** @file    00-Blink.ino
 *  @author  Jorge Villalobos Carvajal (jorgemvc@gmail.com)
 *  @date    19.Ago.2019  
 *  @version 1.0
 *  
 *  @brief   Parpadeo de un led
 *
 *  @licence  MIT License
 */
int pinLed = 3;           // Puerto del pinLed (PWM)

void setup() {
  // ---- Declara el puerto del pinLed como salida
  pinMode(pinLed, OUTPUT);
}  // void setup

void loop() {
  // Enciende el pinLed por un segundo (1000 milisegundos)
  digitalWrite(pinLed, HIGH);
  delay(1000);

  // Apaga el pinLed por un segundo (1000 milisegundos)
  digitalWrite(pinLed, LOW);
  delay(1000);
} // void setup
