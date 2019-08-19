/** @file    14-Servo.ino
 *  @author  Jorge Villalobos Carvajal (jorgemvc@gmail.com)
 *  @date    19.Ago.2019  
 *  @version 1.0 
 *  
 *  @brief   Uso de servo motor
 *
 *  @licence  MIT License
 */
#include <Servo.h>

Servo myservo;   // Instancia de un servo
int 
  potPin   = A0, // Puerto analógico del potenciómetro
  servoPin = 11, // Puerto PWM para manejo del Servo
  val;           // Lectura del potenciometro [0-1023]

void setup() {
  myservo.attach(servoPin);  // Crea la instancia y asigna el puerto
}  // void setup

void loop() {
  val = analogRead(potPin);            // Lee el valor del potenciómetro
  val = map(val, 0, 1023, 0, 180);     // Traduce la lectura a los valores del servo [0-180]
  myservo.write(val);                  // Establece la posición
  delay(15);                           // Espera para que el servo se posicione
}  // void loop
