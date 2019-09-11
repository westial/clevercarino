/*
 * clevercarino.h
 *
 *  Created on: Aug 26, 2019
 *      Author: jaume
 */

#ifndef CLEVERCARINO_H_
#define CLEVERCARINO_H_

#include <Arduino.h>

#include <behavior.h>
#include <inoCapabilities.h>

#include <IRremote.h>
#include <Servo.h>

#include "beeper.h"
#include "groundFace.h"
#include "infraRed.h"
#include "servoMotor.h"
#include "traction.h"
#include "ultraSonicFace.h"

void info();

//
// Definitions
//

void delayMillis(int milliseconds) {
	// Serial.print("Delay milliseconds = ");
	// Serial.println(milliseconds);
	delay(milliseconds);
}

void driveTo(Traction *traction, behavior request) {
	switch (request) {
	case BH_FRONT:
		traction->front(DEFAULT_SPEED);
		break;
	case BH_FRONT_RIGHT:
		traction->frontRight(DEFAULT_SPEED);
		break;
	case BH_RIGHT:
		traction->right(DEFAULT_SPEED);
		break;
	case BH_BACK_RIGHT:
		traction->backRight(DEFAULT_SPEED);
		break;
	case BH_BACK:
		traction->back(DEFAULT_SPEED);
		break;
	case BH_BACK_LEFT:
		traction->backLeft(DEFAULT_SPEED);
		break;
	case BH_LEFT:
		traction->left(DEFAULT_SPEED);
		break;
	case BH_FRONT_LEFT:
		traction->frontLeft(DEFAULT_SPEED);
		break;
	}
}

// Traction ----------------------------------------------------- //

void forwardLeft(void) {
	// Serial.println("Wheel forward Left");
	digitalWrite(dir1PinL, HIGH);
	digitalWrite(dir2PinL, LOW);
}

void rewindLeft(void) {
	// Serial.println("Wheel rewind Left");
	digitalWrite(dir1PinL, LOW);
	digitalWrite(dir2PinL, HIGH);
}

void stopLeft(void) {
	// Serial.println("Wheel stop Left");
	digitalWrite(dir1PinL, LOW);
	digitalWrite(dir2PinL, LOW);
}

void forwardRight(void) {
	// Serial.println("Wheel forward Right");
	digitalWrite(dir1PinR, HIGH);
	digitalWrite(dir2PinR, LOW);
}

void rewindRight(void) {
	// Serial.println("Wheel rewind Right");
	digitalWrite(dir1PinR, LOW);
	digitalWrite(dir2PinR, HIGH);
}

void stopRight(void) {
	// Serial.println("Wheel stop Right");
	digitalWrite(dir1PinR, LOW);
	digitalWrite(dir2PinR, LOW);
}

void setMotorSpeed(int speedLeft, int speedRight) {
	// Serial.print("Set Motor Speed speedLeft = ");
	// Serial.print(speedLeft);
	// Serial.print(", speedRight = ");
	// Serial.println(speedRight);
	analogWrite(speedPinL, speedLeft);
	analogWrite(speedPinR, speedRight);
}

// Ground face ----------------------------------------------------- //

int groundWatch() {
	int sensorvalue = 32;
	int sensor[5];
	sensor[0] = digitalRead(LFSensor_0);
	sensor[1] = digitalRead(LFSensor_1);
	sensor[2] = digitalRead(LFSensor_2);
	sensor[3] = digitalRead(LFSensor_3);
	sensor[4] = digitalRead(LFSensor_4);
	sensorvalue += (sensor[0] * 16) + (sensor[1] * 8) + (sensor[2] * 4)
			+ (sensor[3] * 2) + sensor[4];
	return sensorvalue;
}

// Infrared Control ----------------------------------------------------- //

IRrecv IR(IR_PIN);  	// IRrecv object  IR get code from IR remoter
decode_results IRresults;

/**
 * Listen IR remote control.
 * Returns -1 when there is no order and an integer if does.
 */
int remoteControlTick() {
	int result = -1;
	int behaviorTraslation = -1;
	if (IR.decode(&IRresults)) {
		result = IRresults.value;
		// Serial.println(result, HEX);
		switch (result) {

		case IR_VALUE_ASTERISK:
			// Serial.println("Manual BH_AUTO");
			behaviorTraslation = BH_AUTO;
			break;

		case IR_VALUE_0:
			// Serial.println("Manual INFO");
			info();
			break;

		case IR_VALUE_5:
		case IR_VALUE_OK:
		case IR_VALUE_REDIAL:
			// Serial.println("Manual BH_STOP");
			behaviorTraslation = BH_STOP;
			break;

		case IR_VALUE_2:
		case IR_VALUE_FRONT:
			// Serial.println("Manual BH_FRONT");
			behaviorTraslation = BH_FRONT;
			break;

		case IR_VALUE_1:
			// Serial.println("Manual BH_FRONT_LEFT");
			behaviorTraslation = BH_FRONT_LEFT;
			break;

		case IR_VALUE_4:
		case IR_VALUE_LEFT:
			// Serial.println("Manual BH_LEFT");
			behaviorTraslation = BH_LEFT;
			break;

		case IR_VALUE_7:
			// Serial.println("Manual BH_BACK_LEFT");
			behaviorTraslation = BH_BACK_LEFT;
			break;

		case IR_VALUE_8:
		case IR_VALUE_BACK:
			// Serial.println("Manual BH_BACK");
			behaviorTraslation = BH_BACK;
			break;

		case IR_VALUE_9:
			// Serial.println("Manual BH_BACK_RIGHT");
			behaviorTraslation = BH_BACK_RIGHT;
			break;

		case IR_VALUE_6:
		case IR_VALUE_RIGHT:
			// Serial.println("Manual BH_RIGHT");
			behaviorTraslation = BH_RIGHT;
			break;

		case IR_VALUE_3:
			// Serial.println("Manual BH_FRONT_RIGHT");
			behaviorTraslation = BH_FRONT_RIGHT;
			break;

		}
		IRresults.value = 0;
		IR.resume();
	}
	return behaviorTraslation;
}

// Servo motor ----------------------------------------------------- //

Servo head;

/**
 * Turn head by the given degrees.
 * Degrees go from 10 to 170, 90 is the front position.
 * Degrees for this servo motor cannot arrive at 180.
 */
void turnHeadDegrees(int degrees) {
	head.write(degrees);
	Serial.print("Turned head degrees = ");
	Serial.println(degrees);
	delay(TURN_WATCH_MILLIS);
}

// Beeper ----------------------------------------------------- //

void beepMillis(int milliseconds) {
	int buzzState;
	digitalRead(BUZZ_PIN);
	if (SILENT_BUZZ == 0) {
		digitalWrite(BUZZ_PIN, LOW);     // open buzzer
		delay(milliseconds);
		digitalWrite(BUZZ_PIN, HIGH);    // close buzzer
	}
}

// Ultrasonic face ----------------------------------------------------- //

/**
 * Check obstacle distance in cm by ultrasonic sensor.
 * Returns cm until obstacle.
 */
bool sonicWatch() {
	long howfar;
	digitalWrite(Trig_PIN, LOW);
	delayMicroseconds(5);
	digitalWrite(Trig_PIN, HIGH);
	delayMicroseconds(15);
	digitalWrite(Trig_PIN, LOW);
	howfar = pulseIn(Echo_PIN, HIGH);
	howfar = howfar * 0.01657; 		// how far away is the object in cm
	Serial.print((int) howfar);
	Serial.println(" cm");
	return round(howfar) < DISTANCE_CM;
}

#endif /* CLEVERCARINO_H_ */
