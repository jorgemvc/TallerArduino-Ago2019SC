/** @file    13-Semaforo.h
 *  @author  Jorge Villalobos Carvajal (jorgemvc@gmail.com)
 *  @date    19.Ago.2018  
 *  @version 1.0 
 *  
 *  @brief   Semaforo.
 *
 *  @licence  MIT License
 */
// ---- Variables
int
  i,
  tiempo = 5,
  ledVerde = 3,   // Puerto utilizado para el led rojo
  ledRojo  = 4,
  buzzer   = 8,
  bot      = 2;   // Puerto utilizado por el botón
bool alarma;

void setup() {
  pinMode(bot, INPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(buzzer, OUTPUT);
  alarma = false;
  i = 0;
}  // setup

void loop() {
  if (alarma) {
    i = 0;
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledRojo,  HIGH);
    tone(buzzer, 700, 10);
    if (digitalRead(bot) == HIGH) {
      alarma = false;
    }
    // Se agrega un tiempo de espera para mejorar
    // la simulación.
    delay(10);
  } else {
    noTone(buzzer);
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledRojo,  LOW);
    delay(1000);
    i++;
    if (i >= tiempo) {
      alarma = true;
    }
  }
}  // loop
