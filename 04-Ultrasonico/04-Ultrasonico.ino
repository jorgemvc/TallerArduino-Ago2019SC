/** @file    04-Ultrasonico.ino
 *  @author  Jorge Villalobos Carvajal (jorgemvc@gmail.com)
 *  @date    19.Ago.2019
 *  @version 1.0 
 *  
 *  @brief   Lectura de un sensor ultrasonico
 *
 *  @licence  MIT License
 */
// ---- Constantes
const int   trigPin = 9;     // Puerto de envío
const int   echoPin = 10;    // Puerto de recepción

// ---- Variables
float
  duration,                  // Tiempo de vuelo
  distance;                  // Distancia en cm

void setup() {
  pinMode(trigPin, OUTPUT);  // Establece el puerto como de salida
  pinMode(echoPin, INPUT);   // Establece el puerto como de entrada
  Serial.begin(9600);        // Inicia la comunicación serial
}  // void setup

void loop() {
  //  Limpia el puerto de envío
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Pone el puerto de envío en HIGH por 5 microsegundos
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Lee la señal de regreso de la onda de sonido en microsegundos
  duration = pulseIn(echoPin, HIGH);
  
  // Calcula la distancia
  distance = ((duration / 2.0) / 29.4118);

  // Muestra el resultado en el monitor serial
  Serial.print("Distancia en cm: ");
  Serial.print(distance);
  Serial.print(" - duracion: ");
  Serial.println(duration);

  // Muestra el resultado para el Serial Plotter
  Serial.print(distance);
  Serial.print(",");
  Serial.println(duration);
} // void loop
