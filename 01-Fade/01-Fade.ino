/** @file    01-Fade.ino
 *  @author  Jorge Villalobos Carvajal (jorgemvc@gmail.com)
 *  @date    19.Ago.2019  
 *  @version 1.0 
 *  
 *  @brief   Disminuir/aumentar la luminosidad de un led
 *           conectado a un puerto PWM
 *
 *  @licence  MIT License
 */
int
  led = 3,           // Puerto PWM del led
  espera = 25,       // Milisegundos de espera
  brillo = 0,        // Brillo del led [0-255]
  incremento = 5;    // Incremento del brillo

void setup() {
  // ---- Declara el puerto del led como salida
  pinMode(led, OUTPUT);
}  // void setup

void loop() {
  // ---- Se establece el brillo del led
  analogWrite(led, brillo);

  // ---- Se incrementa el brillo
  brillo += incremento;

  // ---- Invierte el incremento si llega a algún
  //      límite de los valores posibles
  if (brillo <= 0 || brillo >= 255) {
    incremento = -incremento;
  }

  // Espera 100 milisegundos
  delay(espera);
} // void setup
