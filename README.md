# HC-SR04 Distance Sensor with Arduino Uno R4 WiFi

## Overview
Simple project that measures distance using the HC-SR04 ultrasonic sensor and prints the result over serial. Main sketch is in `src/main.cpp` and the build configuration is in `platformio.ini`.

## Hardware
- Arduino Uno R4 WiFi
- HC-SR04 ultrasonic sensor
- Jumper wires
- Breadboard (optional)
- 5V power from the board

## Wiring
- `VCC` -> 5V on `Arduino Uno R4 WiFi`
- `GND` -> GND on `Arduino Uno R4 WiFi`
- `TRIG` -> digital pin 9 (matches `triggerPin` in `src/main.cpp`)
- `ECHO` -> digital pin 10 (matches `echoPin` in `src/main.cpp`)

Make sure `TRIG` and `ECHO` are connected to the same logic voltage (5V) and grounds are common.

## Software / Code
The sketch in `src/main.cpp`:
- Initializes `Serial` at 9600 baud.
- Configures `triggerPin` as `OUTPUT` and `echoPin` as `INPUT`.
- Sends a 10 µs pulse on `TRIG`, reads the echo pulse width via `pulseIn`.
- Calculates distance using the speed of sound and prints `Distance: <value> cm` every second.

Important serial setting: 9600 baud.

## PlatformIO (`platformio.ini`)
Use `platformio.ini` in the project root to set the board to `uno` / `uno_r4_wifi` (or the PlatformIO board ID that matches Arduino Uno R4 WiFi), framework to `arduino`, and the correct upload protocol if needed. Example keys:
- `board` — board id for Uno R4 WiFi
- `framework = arduino`
- `monitor_speed = 9600`

(Do not forget to match the exact board id used by PlatformIO for the Uno R4 WiFi.)

## Build & Upload (PlatformIO)
- Open project in your IDE (CLion with PlatformIO plugin or PlatformIO CLI).
- Build: `pio run`
- Upload: `pio run --target upload`
- Monitor serial: `pio device monitor --baud 9600` or use the IDE serial monitor.

## Troubleshooting
- No serial output: confirm USB connection and select correct serial port, ensure `Serial.begin(9600)` speed matches monitor.
- Incorrect distances: verify wiring, ensure `TRIG` and `ECHO` pins match `src/main.cpp`, keep sensor clear of obstruction during measurement.
- `pulseIn` timeout: check `ECHO` wiring and sensor power.

## License
MIT License — adapt and reuse as needed.
