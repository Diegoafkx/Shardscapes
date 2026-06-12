# Shardscapes - WRO Future Engineers 2026

Welcome to the official repository for Team Shardscapes. This project contains the software, mechanical designs, and technical documentation for our autonomous vehicle competing in the WRO Future Engineers 2026 category.

## Project Structure
- **/src**: Arduino C++ source code (PlatformIO framework).
- **/models**: 3D design files and CAD models of our autonomous chassis.
- **/schematics**: Electrical diagrams and wiring photos.
- **/docs**: Additional technical manuals and testing logs.

## Technical Specifications
- **Main Controller**: Arduino UNO.
- **Actuators**: DC Motor for propulsion and Servo motor for steering.
- **Sensors**: Ultrasonic sensors, line sensors, and IMU for navigation.

## Getting Started
To compile the code, ensure you have **PlatformIO** installed in VS Code.
1. Clone this repository.
2. Open the project folder in VS Code.
3. The `platformio.ini` file will automatically manage dependencies, including the required `Servo` library.

---
*Built for the WRO 2026 Future Engineers Challenge.*