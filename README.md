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

## Bill of Materials (BOM) & Hardware Specifications
The following section outlines the mechanical and electronic components integrated into our autonomous vehicle platform. Each part has been selected to meet the technical constraints and high-performance requirements of the WRO Future Engineers competition.
### Component List

| Component Name | Quantity | Description / Technical Purpose |
| :--- | :--- | :--- |
| **Arduino Uno R3** | 1 | Main microcontroller board responsible for processing sensor inputs, executing control loops, and generating PWM signals for steering and speed logic. |
| **DC Drive Motor** | 1 | High-torque main propulsion motor connected to the drivetrain to provide steady acceleration and consistent speed control. |
| **Servo Motor** | 1 | Dedicated high-precision actuator linked directly to the front assembly to handle steering control (Ackermann geometry style). |
| **MH-Bridge Motor Driver** | 1 | H-Bridge speed controller interface used to handle power distribution and safely drive the high-current DC motor using control signals from the Arduino. |
| **High-Grip Wheels** | 4 | Set of four specialized robotic wheels optimized to maintain absolute traction on the track surface and minimize slippage during sharp maneuvers. |

### Hardware Architecture Overview
The vehicle features a rear-wheel-drive and front-wheel-steering configuration. The single **DC Drive Motor** handles the vehicle's propulsion via the **MH-Bridge driver**, allowing smooth acceleration and precise forward/reverse braking. Directional steering is actuated independently by the **Servo Motor** on the front axle. The **Arduino Uno** serves as the central brain, bridging real-time processing and structural power management.
---
*Built for the WRO 2026 Future Engineers Challenge.*
