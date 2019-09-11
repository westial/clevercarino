#include <Arduino.h>

#include <TractionCommand.h>
#include <ControlSensor.h>
#include <Beeper.h>
#include <FaceSensor.h>
#include <Reviser.h>
#include <Traction.h>
#include <Driver.h>
#include <Nav.h>

#include <InoBeeper.h>
#include <InoControlSensor.h>
#include <InoGroundFaceSensor.h>
#include <InoSonicFaceSensor.h>
#include <InoDriver.h>
#include <InoTraction.h>
#include <InoNav.h>

#include <InoBackLeftReviser.h>

#include "clevercarino.h"

using namespace clevercarino;

bool autoMode;

Beeper *inoBeeper;

ControlSensor *inoSensor;

FaceSensor *inoGroundFaceSensor;

FaceSensor *inoSonicFaceSensor;

Driver *inoDriver;

Reviser *inoReviser;

Traction *inoTraction;

Nav *inoNav;

int loopsCounter;

void initComponents() {
	Serial.println("Init Components");

	inoBeeper = new InoBeeper(beepMillis, DURATION_LONG, DURATION_SHORT);

	inoSensor = new InoControlSensor(remoteControlTick);

	inoGroundFaceSensor = new InoGroundFaceSensor(groundWatch);

	inoSonicFaceSensor = new InoSonicFaceSensor(sonicWatch, turnHeadDegrees);

	inoDriver = new InoDriver(delayMillis, forwardLeft, rewindLeft, stopLeft,
			forwardRight, rewindRight, stopRight, setMotorSpeed,
			PERCENT_SPEED_DIFF);

	inoReviser = new InoBackLeftReviser(inoDriver);

	inoNav = new InoNav(TURNING_DEGREES_FACTOR, SPEED_CONVERTER_FACTOR,
			PERCENT_SPEED_DIFF);

	inoTraction = new InoTraction(inoDriver, inoReviser, inoNav,
			DRIVER_REQUEST_DURATION, SLIGHT_TURN_DEGREES);
}

void info() {
	Serial.print("Absolute angle = ");
	Serial.println(inoTraction->getAbsoluteAngle());

	Serial.print("Distance traveled = ");
	Serial.println(inoTraction->getDistanceTraveled());
}

void setup() {
	Serial.begin(9600);
	Serial.println("Started");

	pinMode(dir1PinL, OUTPUT);
	pinMode(dir2PinL, OUTPUT);
	pinMode(speedPinL, OUTPUT);
	pinMode(dir1PinR, OUTPUT);
	pinMode(dir2PinR, OUTPUT);
	pinMode(speedPinR, OUTPUT);

	pinMode(Trig_PIN, OUTPUT);
	pinMode(Echo_PIN, INPUT);

	pinMode(BUZZ_PIN, OUTPUT);
	digitalWrite(BUZZ_PIN, HIGH);   // Buzz off

	pinMode(LFSensor_0, INPUT);
	pinMode(LFSensor_1, INPUT);
	pinMode(LFSensor_2, INPUT);
	pinMode(LFSensor_3, INPUT);
	pinMode(LFSensor_4, INPUT);

	digitalWrite(Trig_PIN, LOW);

	head.attach(SERVO_PIN); 	// servo
	head.write(90);

	// IR Remote setup
	pinMode(IR_PIN, INPUT);
	digitalWrite(IR_PIN, HIGH);
	IR.enableIRIn();

	// clevercapp library initializations

	autoMode = false;
	initComponents();

	// Set loops counter
	loopsCounter = 0;
}

void loop() {

	behavior request = inoSensor->listen();

	switch (request) {

	case BH_AUTO:
		autoMode = true;
		inoTraction->resetNavigation();
		break;

	case BH_STOP:
		autoMode = false;
		inoTraction->resetNavigation();
		break;
	}

	if (autoMode) {

		// Auto mode
		// Serial.println("Auto mode is ON");

		int blockedDirections;
    
		if (!inoGroundFaceSensor->isFaceFree()) {

			// Ground detector warning

      inoTraction->stop(0);
			Serial.println("Ground Face stopped traction");
			inoBeeper->beep();
			blockedDirections = inoGroundFaceSensor->getBlockedDirections();
			Serial.print("Ground blocked directions = ");
			Serial.println(blockedDirections);
			inoTraction->revise(blockedDirections, DEFAULT_SPEED);

		} else if (loopsCounter % ROUTINARY_SONIC_CHECK_EVERY_LOOPS == 0) {

			// Ultrasonic detector routinary checking

      inoTraction->stop(0);
			Serial.println("Sonic Face stopped traction for routinary check");
			blockedDirections = inoSonicFaceSensor->getBlockedDirections();
			if (blockedDirections != 0) {
				inoBeeper->beep();
				Serial.print("Sonic blocked directions = ");
				Serial.println(blockedDirections);
				inoTraction->revise(blockedDirections, DEFAULT_SPEED);
			}

		} else if (!inoSonicFaceSensor->isFaceFree()) {

			// Ultrasonic detector warning

      inoTraction->stop(0);
			Serial.println("Sonic Face stopped traction");
			inoBeeper->beep();
			blockedDirections = inoSonicFaceSensor->getBlockedDirections();
			Serial.print("Sonic blocked directions = ");
			Serial.println(blockedDirections);
			inoTraction->revise(blockedDirections, DEFAULT_SPEED);

		} else {
      
		  inoTraction->front(AUTO_SPEED);
		}

	} else {

		// Manual control request
		// Serial.println("Auto mode is OFF");

		driveTo(inoTraction, request);

		delay (MANUAL_MODE_TICK_MILLIS);
		inoTraction->stop(0);
	}

	loopsCounter++;
}
