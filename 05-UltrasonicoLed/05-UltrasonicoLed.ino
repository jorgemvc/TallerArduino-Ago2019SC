/** @file    05-UltrasonicoLed.ino
 *  @author  Jorge Villalobos Carvajal (jorgemvc@gmail.com)
 *  @date    19.Ago.2019  
 *  @version 1.0 
 *  
 *  @brief   Lectura de un sensor ultrasonico y refleja la
 *           cercanía por medio del brillo en un led
 *
 *  @licence  MIT License
 */
// ---- Constantes
const int   trigPin = 9;     // Puerto de envío
const int   echoPin = 10;    // Puerto de recepción
const int   ledPin  = 3;     // Puerto del led (PWM)

// ---- Variables
float
  duracion,                  // Tiempo de vuelo
  distancia;                  // Distancia en cm
int brillo;

void setup() {
  pinMode(trigPin, OUTPUT);  // Establece el puerto como de salida
  pinMode(echoPin, INPUT);   // Establece el puerto como de entrada
  pinMode(ledPin , OUTPUT);
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
  duracion = pulseIn(echoPin, HIGH);
  
  // Calcula la distancia
  distancia = ((duracion / 2.0) / 29.4118);

  distancia = constrain(distancia, 3, 300);

  brillo = constrain(distancia, 5, 20);
  brillo = map(brillo, 5, 20, 0, 255);
  analogWrite(ledPin, brillo);
  
  // Muestra el resultado en el monitor serial
  Serial.print("Distancia en cm: ");
  Serial.print(distancia);
  Serial.print(" - brillo: ");
  Serial.println(brillo);

  // Muestra el resultado para el Serial Plotter
//  Serial.print(distancia);
//  Serial.print(",");
//  Serial.println(brillo);
} // void loop
