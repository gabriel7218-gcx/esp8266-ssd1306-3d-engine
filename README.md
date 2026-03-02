# ESP8266 3D Engine

A lightweight 3D graphics engine designed to run on the ESP8266 microcontroller.
It renders simple 3D objects in real time using optimized math and minimal memory, demonstrating basic transformations and perspective projection on highly constrained hardware.

This project focuses on low-level graphics programming and efficient use of embedded resources.

## Features
- Real-time 3D object rendering
- Rotation, translation, and perspective projection
- Optimized for low memory usage
- Designed specifically for embedded systems

## Hardware Requirements
- ESP8266 microcontroller
- **SSD1306 OLED display** (only supported display)

## Wiring
I²C connection:
- **SDA -> D5**
- **SCL -> D7**

## Payloads
The engine includes several built-in rendering demos:
- Double cube
- Sierpinski triangle
- Sphere composed of smaller spheres
- Torus

These payloads are designed to demonstrate transformations, depth perception, and rendering performance under tight hardware constraints.

## Display Support
This engine currently supports **only SSD1306-based displays**. Other display controllers are not supported.

## Dependencies
- ESP8266WiFi.h
- Adafruit-GFX.h
- Adafruit-SSD1306.h

## Purpose
This project is an experiment in pushing the limits of microcontroller graphics and exploring how far real-time rendering can go on minimal hardware.
