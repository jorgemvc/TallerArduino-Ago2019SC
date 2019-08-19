/** @file    12-BuzzerV2.ino
 *  @author  Jorge Villalobos Carvajal (jorgemvc@gmail.com)
 *  @date    19.Ago.2019  
 *  @version 2.0 
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
  PlayStarWars();
  Serial.println("Taller - Buzzer v2 | JVC 2019");
}  // void setup

void loop() {
}  // void loop

void PlayStarWars() {
  int numNotas = 20;

  // Para las matrices SI es necesario definir sus dimensiones
  int notas[20][2] = {
    {a , 500}, {a , 500}, {a , 500}, {f , 350}, 
    {cH, 150}, {a , 500}, {f , 350}, {cH, 150},
    {a , 650}, {0 , 500}, {eH, 500}, {eH, 500}, 
    {eH, 500}, {fH, 350}, {cH, 150}, {gS, 500},
    {f , 350}, {cH, 150}, {a , 650}, {0 , 500}  
  };
  for (int i = 0 ; i < numNotas ; i++) {    
    if (notas[i][0] > 0) {
      tone(pinBuzzer, notas[i][0], notas[i][1]);
    }
    delay(notas[i][1]);
    noTone(pinBuzzer);

    delay(50);
  }  // for
} // void PlayStarWars
