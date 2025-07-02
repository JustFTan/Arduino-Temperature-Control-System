# Arduino Temperature Control System

This project is an Arduino-based temperature control system that uses a DHT11 temperature sensor, a cooling fan, a buzzer, and an I2C LCD display to monitor and control the temperature of an environment. The system provides real-time temperature readings and activates the fan or buzzer based on temperature thresholds.

## Features

- **Temperature Monitoring:** Measures current temperature using the DHT11 sensor.
- **LCD Display:** Shows system status and temperature on a 16x2 I2C LCD.
- **Fan Control:** Turns on the cooling fan when the temperature exceeds a set threshold.
- **Overheat Alarm:** Activates a buzzer and displays a warning message when the temperature is critically high.
- **Serial Output:** Prints current temperature readings to the Serial Monitor for debugging or data logging.

## Hardware Requirements

- Arduino board (Uno, Nano, Mega, etc.)
- DHT11 Temperature and Humidity Sensor
- 16x2 I2C LCD Display (address 0x27)
- Cooling Fan (connected to digital pin 4)
- Buzzer (connected to digital pin 3)
- Jumper wires
- Breadboard or PCB

## Wiring Diagram

| Component         | Arduino Pin |
|-------------------|------------|
| DHT11 Data        | 5          |
| Fan               | 4          |
| Buzzer            | 3          |
| LCD (I2C)         | SDA/SCL    |

> **Note:** Ensure the I2C address of your LCD is 0x27. If not, change it in the code.

## How It Works

1. **Startup:** The system initializes the LCD and displays a welcome message.
2. **Temperature Reading:** The DHT11 sensor reads the temperature every 500 ms.
3. **Control Logic:**
    - If temperature < 30°C: System stays in cooling mode (fan off).
    - If 30°C < temperature < 40°C: Fan turns on, buzzer stays off.
    - If temperature > 40°C: Buzzer turns on, and an overheat warning is displayed.

## Arduino Libraries Required

- [DHT sensor library](https://github.com/adafruit/DHT-sensor-library)
- [LiquidCrystal I2C library](https://github.com/johnrickman/LiquidCrystal_I2C)

## Usage

1. Connect all components as per the wiring diagram.
2. Install the required libraries in the Arduino IDE.
3. Upload the `main.ino` file to your Arduino board.
4. Open the Serial Monitor (9600 baud) to view temperature logs.

## Code Overview

- `DHTPIN` is set to pin 5, `FAN` to pin 4, and `BUZZER` to pin 3.
- The LCD displays the system status and temperature.
- The fan and buzzer are activated according to temperature thresholds.
