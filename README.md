# Bionic Hand Arduino Code

## Overview
This repository contains the Arduino code for simulating the flexion and extension of a bionic hand. The simulation utilizes five servo motors and MyoWare EMG sensors to mimic human hand movements based on muscle activity data.

## Features
- **Servo Motor Control:** Controls five servo motors to simulate hand movements.
- **EMG Signal Processing:** Uses MyoWare EMG sensors with a non-inverting amplifier (100x amplification) and a low-pass filter with a cutoff frequency of 28 Hz to detect and process muscle activity.
- **OLED Display:** Utilizes an OLED display to provide real-time feedback on the status and readings from the EMG sensors.

## Hardware Requirements
- Arduino Board
- 5x Servo Motors
- MyoWare EMG Sensor Kit
- Non-inverting Amplifier
- Low-Pass Filter
- Adafruit SSD1306 OLED Display

## Circuit Design
![Schematic Diagram](Schematic.png)

## Schematic Diagram
![Schematic Diagram](Visual.png)

## Software Dependencies
- `Servo.h` - For controlling the servo motors.
- `Wire.h`, `Adafruit_GFX.h`, `Adafruit_SSD1306.h` - For handling the OLED display.

## Installation
1. Connect all hardware components according to the circuit diagram provided.
2. Download and install the Arduino IDE from the [official Arduino website](https://www.arduino.cc/en/software).
3. Install the libraries mentioned in the Software Dependencies section through the Library Manager in the Arduino IDE.
4. Upload the code to your Arduino board.

## Usage
After setting up the hardware and uploading the code:
1. Power on the system.
2. Observe the hand movements and OLED display outputs as the EMG sensors detect muscle activity.

## Contributing
Feel free to fork this repository and contribute by submitting pull requests or by creating issues for bugs and feature requests.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE.md) file for details.
