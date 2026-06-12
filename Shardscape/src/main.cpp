#include <Arduino.h>
#include <Servo.h> // Ahora PlatformIO la reconocerá gracias al lib_deps

// Definición de pines para el Puente H
const int IN1 = 12;
const int IN2 = 14;
const int ENA = 27; 

// Definición para el Servomotor
const int PIN_SERVO = 9; // Elige un pin PWM libre (ej. 9, 10 o 11 en Arduino Uno)
Servo direccion; 

void setup() {
  // Configuración de Puente H
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  
  // Configuración de Servomotor
  direccion.attach(PIN_SERVO);
  direccion.write(90); // Posición central (0-180 grados)
  
  Serial.begin(9600);
}

void loop() {
  // --- Lógica de Movimiento ---
  
  // 1. Mover hacia adelante
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 150); 
  
  // 2. Girar dirección
  direccion.write(45); // Ángulo de giro a la izquierda
  
  Serial.println("Motor avanzando y girando...");
  delay(2000);

  // 3. Detener motor
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
  
  delay(1000);
}
