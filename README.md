# Water Bottle Project

This project is a smart water bottle application written in C++ for Arduino. It uses a Liquid Crystal I2C LCD for display and a SparkFun ADXL345 accelerometer for motion detection.

## Dependencies

- LiquidCrystal_I2C.h: This library allows an Arduino board to control LiquidCrystal displays (LCDs) based on the Hitachi HD44780 (or a compatible) chipset, which is found on most text-based LCDs.
- SparkFun_ADXL345.h: This library is used to communicate with the ADXL345 Triple Axis Accelerometer.

## Hardware Components

- LiquidCrystal I2C LCD: The LCD is used to display information to the user. The address of the LCD module is set to 0x27 and it has 16 columns and 2 rows.
- Buttons: There are three buttons connected to the Arduino, assigned to pins 6, 7, and 8.
- Buzzer: A buzzer is connected to pin 9 of the Arduino. It is used to alert the user.
- ADXL345 Accelerometer: This is used to detect the motion of the water bottle.

## Variables

- `totalWater`: This variable holds the total water consumption.
- `displayMode`: This variable controls what is displayed on the LCD. 0 for time display, 1 for water consumption display, 2 for reminder timer.
- `remindTime`: This variable holds the reminder time in minutes.
- `buzzerOn`: This boolean variable controls whether the buzzer is on or off.

## Setup

In the `setup()` function, the LCD is initialized and the backlight is turned on.

## Further Development

The code snippet provided does not show the main loop of the program. The main loop would likely read the button inputs, update the display, read the accelerometer, and control the buzzer based on the user's water consumption and the reminder time.
