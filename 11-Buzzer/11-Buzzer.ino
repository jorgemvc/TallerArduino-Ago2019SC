/** @file    11-Buzzer.ino
 *  @author  Jorge Villalobos Carvajal (jorgemvc@gmail.com)
 *  @date    19.Ago.2019  
 *  @version 1.0 
 *  
 *  @brief   Uso de un zumbador / buzzer
 *
 *  @licence  MIT License
 */
// ---- Bibliotecas
#include "Notas.h"

// ---- Constantes
#define pinBuzzer 8

// -- Variables

void setup() {
  Serial.begin(9600);  
  Serial.println("Taller - Buzzer | JVC 2019");
  PlayStarWars();
}  // void setup

void loop() {
}  // void loop

void PlayStarWars() {
  int numNotas = 20;
  int notas[]    = {a  , a  , a  , f  , cH , a  , f  , cH , a  , 0  , eH , eH , eH , fH , cH , gS , f  , cH , a  , 0  };
  int duracion[] = {500, 500, 500, 350, 150, 500, 350, 150, 650, 500, 500, 500, 500, 350, 150, 500, 350, 150, 650, 500};

  for (int i = 0 ; i < numNotas ; i++) {
    if (notas[i] > 0) {
      tone(pinBuzzer, notas[i], duracion[i]);
    }
    delay(duracion[i]);
    noTone(pinBuzzer);

    delay(50);
  }  // for
} // void PlayStarWars
