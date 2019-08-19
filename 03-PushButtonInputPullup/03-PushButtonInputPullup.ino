/** @file    02-PushButtonInputPullup.ino
 *  @author  Jorge Villalobos Carvajal (jorgemvc@gmail.com)
 *  @date    19.Ago.2019  
 *  @version 1.0 
 *  
 *  @brief   Uso de un pulsador con entrada PULLUP.
 *
 *  @licence  MIT License
 */
// ---- Variables
int
  pinLed   = 3,   // Puerto utilizado para el led
  pinBoton = 2;   // Puerto utilizado por el boton

void setup() {
  pinMode(pinBoton, INPUT_PULLUP);
  pinMode(pinLed  , OUTPUT);
}  // setup

void loop() {
  // Cuando se utiliza una entrada PULLUP la lógica se
  // invierte, dando LOW cuando se oprime el botón y
  // HIGH cuando no.
  if (digitalRead(pinBoton) == LOW) {
    digitalWrite(pinLed, HIGH);
  } else {
    digitalWrite(pinLed, LOW);
  }
  // Se agrega un tiempo de espera para mejorar
  // la simulación.
  delay(10); 
} // loop
