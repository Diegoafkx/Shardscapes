#include <Arduino.h>
#include <WiFi.h>
#include <ArduinoOTA.h>

int loops;
int distance_acording;
int velocity;
int distance_calculated;
int x;
unsigned long tiempoAnterior = 0;
const char *ssid = "Arreaza_2.4GHz";
const char *password = "Da09052006";

void aux_programacion_wifi(){
     // Must match monitor_speed in platformio.ini
    
    WiFi.begin (ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    ArduinoOTA.onStart([]() { Serial.println("Inicio de actualización OTA"); });
    ArduinoOTA.onEnd([]() { Serial.println("\nFin de actualización"); });
    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
        Serial.printf("Progreso: %u%%\r", (progress / (total / 100)));
    });
    ArduinoOTA.onError([](ota_error_t error) {
        Serial.printf("Error [%u]\n", error);
    });

    ArduinoOTA.begin();

    Serial.println("\n¡Wi-Fi Conectado!");
    Serial.print("Dirección IP del ESP32: ");
    Serial.println(WiFi.localIP());
    
}

void setup() {
    Serial.begin(115200); 
    aux_programacion_wifi();
    ArduinoOTA.begin();
}

void loop() {
    ArduinoOTA.handle();
    
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}

