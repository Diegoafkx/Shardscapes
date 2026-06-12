#include <Arduino.h>

// Definición de pines para el Puente H
const int IN1 = 12;
const int IN2 = 14;
const int ENA = 27; // Pin con capacidad PWM

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Ejemplo: Mover hacia adelante
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 150); // Velocidad (0-255)
  
  Serial.println("Motor moviéndose...");
  delay(2000);
}