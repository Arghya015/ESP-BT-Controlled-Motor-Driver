# ESP-BT-Controlled-Motor-Driver

A simple, well-documented README for controlling a DC motor using an ESP32 over Bluetooth (Classic SPP) — suitable as the main `README.md` for a Git repository.

---

## Project Overview

This project shows how to control a DC motor (or a pair of motors) from a smartphone via Bluetooth using an ESP32 and a motor driver (L298N / L293D / TB6612). It includes wiring diagrams, example Arduino/PlatformIO code, pairing and usage instructions, and troubleshooting tips.

### Features

* Control motor direction (forward / backward)
* Start / stop motor and set simple speed (PWM)
* Use a smartphone Bluetooth terminal or a custom mobile app
* Safe wiring and basic protection notes

---

## Hardware Required

* ESP32 development board (e.g., DevKitC)
* Motor driver (L298N, L293D or TB6612)
* DC motor (or two)
* External power supply for motor (recommended: 6–12V depending on motor)
* Jumper wires
* Breadboard (optional)
* Diode / capacitor as needed for motor noise suppression

**Pin mapping example (changeable in code):**

* ENA (PWM for motor speed) → ESP32 PWM pin (e.g., 14)
* IN1 → ESP32 GPIO (e.g., 25)
* IN2 → ESP32 GPIO (e.g., 26)
* GND → common ground between ESP32 and motor power supply
* Vmotor → external motor supply (+)

> ⚠️ Do not power the motor directly from the ESP32 5V pin. Motor draws heavier current — use a dedicated supply and common ground.

---

## Wiring (Example with L298N)

1. Connect motor terminals to the motor outputs on the driver.
2. Connect `ENA` (enable) to ESP32 PWM pin (e.g., GPIO14).
3. Connect `IN1` and `IN2` to ESP32 GPIOs for direction (e.g., GPIO25 and GPIO26).
4. Connect driver ground and ESP32 GND together.
5. Connect motor power supply to driver `Vcc`/`12V` input. Set driver 5V jumper according to board and logic supply.
6. Connect ESP32 `5V` (or USB power) to the driver logic `5V` only if required by that driver board — check the driver documentation.

---

## Software

This example uses the Arduino framework for ESP32 (Arduino-ESP32 core). You can also use PlatformIO — the code is compatible.

### Libraries

No special libraries required for basic SPP Bluetooth and PWM control. Use `BluetoothSerial.h` (built-in) for Classic Bluetooth SPP.
