# Clevercarino #

This repository contains the source code for my extended firmware for [OSOYOO Robot Car Starter Kit](http://osoyoo.com/2017/08/06/osoyoo-robot-car-diy-introduction/).

OSOYOO Robot Car Starter Kit is an Arduino based DIY robot with some very useful components, and this source code makes use of the following ones:

* Ultrasonic sensor.
* Servo motor to make utrasonic sensor turn sideways.
* 5 IR Track sensors.
* IR Remote Control.

This OSOYOO smart car fork is called as Clevercarino: clever car with Arduino. Because if the original OSOYOO smart car firmware is quite useful and stable, this development wanted to get smarter this car.

With the OSOYOO firmware, after [lesson 5](http://osoyoo.com/?p=5543) the robot can follow a black tape on floor or it can avoid obstacles, or it can be managed by a smartphone app. 

What I missed in the original firware is doing all together and get used for the real world, where there is no black tape to follow. And these are the improvements:

Clevercarino implement a track and ultrasonic sensors interfaces to work together with the traction system to move the robot car avoidind obstacles and holes.

## Education ##

This OSOYOO Robot Car is a toy and this project is aimed to kids programming education. Due the complexity of this content, it requires an adult with advanced knowledge on Arduino or C/C++ developer assistance.

Actually Clevercarino

## Files ##

This project is divided into two parts:

* clevercarapp: C/C++ library with the interfaces and implementations for an abstract robot. The implementations are decoupled so they need injected functions as dependencies to make the final hardware run.
* clevercarino: Arduino Main entry point and header files implementing the functions that clevercarapp need to make Clevercarino run.

## Requirements ##

### OSOYOO Smart Car full equip ###

First follow the [OSOYOO Lesson 2](http://osoyoo.com/2017/04/16/control-smart-car-with-ir/) to assemble the IR remote control and after the [OSOYOO Lesson 5](http://osoyoo.com/2017/05/14/wifi-control-smart-car/) to get smart car full equip.

Actually all OSOYOO lessons are really recommended, but the hardware variation starts from here, after the Lesson 5.

### IR remote addition ###

At this point the robot car is provided with all sensors, but in the Lesson 5 the IR remote control has been disconnected. The IR remote control has to be enabled again, and we do not need the Bluetooth module in this first release.

In the Lesson 5 there is a table for tracking sensor modules about wich pins connect to the ESP8266 expansion board. You have to ignore that table and connect the pins as in the table below:

| Pins of tracking  | Pins of   ESP8266 |
|---                |---                |
| VCC               | 5V                |
| GND               | GND               |
| (Left1) DO        | (A)0              |
| (Left2) DO        | (A)1              |
| (Left3) DO        | (A)2              |
| (Left4) DO        | (A)3              |
| (Left5) DO        | (D)10             |

Connect IR remote control sensor is connected as follows:

| Pin of IR module  | Pins of   ESP8266 |
|---                |---                |
| VCC               | 5V                |
| GND               | GND               |
| PIN               | (D)3              |

### Arduino IDE ###

[Arduino IDE](https://www.arduino.cc) is totally recommmended to verify and upload the implementation source code. 

The clevercarapp library has been programmed using [Eclipse CDT](https://www.eclipse.org/cdt/).

Thanks to these free tools.

## Install ##

1. Download this repository contents by git.
2. Install the Arduino library "./clevercarino/clevercarapp" by following the [Arduino guidelines](https://www.arduino.cc/en/guide/libraries).
3. Open the Arduino main file "./clevercarino/main/clevercarino.ino" with Arduino IDE, verify and upload it into your OSOYOO Robot Car.

