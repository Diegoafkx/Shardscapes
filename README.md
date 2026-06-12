# Shardscapes - WRO Future Engineers 2026 🚀

Bienvenido al repositorio oficial del equipo **Shardscapes**, participante en la categoría **Future Engineers** de la World Robot Olympiad (WRO) 2026. Este proyecto consiste en el diseño, construcción y programación de un vehículo autónomo capaz de esquivar obstáculos dinámicos, navegar en carriles y estacionarse de forma precisa.

El núcleo de control del vehículo está basado en el microcontrolador **ESP-WROOM-32** programado íntegramente en **MicroPython**.

---

## 🛠️ Arquitectura del Sistema

El robot utiliza una arquitectura modular que separa el procesamiento de bajo nivel (control de motores y actuadores) del procesamiento de alto nivel (visión artificial).

### Hardware Principal
* **Controlador:** ESP32 (ESP-WROOM-32)
* **Actuadores de Tracción:** Motor DC controlado mediante un Puente H (ej. L298N / TB6612FNG).
* **Actuador de Dirección:** Servomotor de alta precisión para el eje delantero.
* **Sistema de Visión:** Cámara inteligente / Sensor de visión autónomo conectado por comunicación serial.

### Conexiones (Pinout sugerido)
| Componente | Pin ESP32 | Función |
| :--- | :--- | :--- |
| **Puente H - IN1** | GPIO 12 | Dirección Motor Tracción |
| **Puente H - IN2** | GPIO 14 | Dirección Motor Tracción |
| **Puente H - PWM** | GPIO 27 | Control de Velocidad (PWM) |
| **Servo Dirección**| GPIO 13 | Ángulo de Giro (PWM) |
| **Cámara Rx** | GPIO 16 | Comunicación UART |
| **Cámara Tx** | GPIO 17 | Comunicación UART |

---

## 📂 Estructura del Repositorio

Siguiendo las regulaciones oficiales de la WRO, el repositorio está organizado de la siguiente manera:

* `models/`: Archivos de diseño 3D (piezas del chasis, soportes de sensores y cámara).
* `schematics/`: Diagramas eléctricos, conexiones de componentes y distribución de potencia.
* `src/`: Código fuente en MicroPython que se ejecuta en el ESP32 (`main.py`, librerías de motores y algoritmos de control).
* `t-photos/`: Fotografías del equipo.
* `v-photos/`: Fotografías detalladas del vehículo desde todos sus ángulos.
* `video/`: Archivo con el enlace directo al video demostrativo en YouTube.

---

## 🧠 Algoritmo y Estrategia de Control

El vehículo ejecuta un ciclo continuo de toma de decisiones basado en los datos recibidos por la unidad de visión:

1.  **Detección de Pilares (Espacio de Color LAB):** Se realiza un filtrado de imagen en el espacio de color LAB para aislar con precisión los contornos de los pilares rojos y verdes bajo cualquier condición de iluminación.
2.  **Control de Dirección Proporcional-Derivativo (PD):** Basado en la distancia horizontal ($X$) respecto al centro de la pista o los pilares, el ESP32 calcula el error y ajusta de forma suave el servomotor mediante un lazo PD para evitar oscilaciones bruscas.
3.  **Maniobras Especiales:** El código incluye rutinas automatizadas para realizar el giro de 3 puntos (cambio de sentido en la tercera vuelta) y la detección de la zona magenta para un estacionamiento en reversa óptimo.

---

## 🚀 Instalación y Ejecución

Para desplegar este código en tu ESP32 utilizando Visual Studio Code:

1.  Instala la extensión **Pymakr** o **MicroPico** en VS Code.
2.  Conecta el ESP32 mediante USB y asegúrate de tener el firmware de **MicroPython** flasheado.
3.  Sincroniza los archivos de la carpeta `src/` directamente en la memoria del microcontrolador.
4.  El archivo `boot.py` inicializará el hardware y `main.py` arrancará la lógica de navegación de forma automática.