/*
 * traction.cpp
 *
 *  Created on: Jun 25, 2019
 *      Author: jaume
 */
#include "util/String.h"
#include "../CommandBus.h"
#include "../TractionCommand.h"
#include "../behavior.h"
#include "../ControlSensor.h"
#include "../Beeper.h"
#include "../FaceSensor.h"
#include "../Reviser.h"
#include "../Traction.h"
#include "../Driver.h"

#include "../inoCapabilities.h"
#include "../InoBeeper.h"
#include "../InoControlSensor.h"
#include "../InoGroundFaceSensor.h"
#include "../InoTraction.h"
#include "../InoDriver.h"
#include "../InoNav.h"

using namespace clevercarino;

#include "mock/Witness.h"
#include "mock/MockTraction.h"
#include "mock/MockReviser.h"
#include "mock/MockBeeper.h"
#include "mock/MockControlSensor.h"
#include "mock/MockFaceSensor.h"

/* ----------------------------------------------------------------- */

int testWitness();
int testCommandBus();
int testBeeper();
int testControlSensor();
int testFaceSensor();

int testInoBeeper();
int testInoControlSensor();
int testBlockedInoGroundFaceSensor();
int testFreeInoGroundFaceSensor();
int testInoGroundFaceSensor(int expectedBlocking, bool expectedFree);
int testInoTraction();

Witness witness = Witness();
Beeper *beeper;
ControlSensor *sensor;
FaceSensor *faceSensor;
Reviser *reviser;
Traction *traction;

int inoControlTickBehavior;
int inoForcedBlockingDirections;
bool inoForcedIsFaceFree;

int inoLeftSpeed;
int inoRightSpeed;

int DRIVER_MOVEMENT_DURATION_MILLIS = 500;
int PERCENT_SPEED_DIFF = 20;
int SLIGHT_TURN_DEGREES = 20;
char FORWARD_WHEEL_STATUS[50] = "forward";
char REWIND_WHEEL_STATUS[50] = "rewind";
char STOP_WHEEL_STATUS[50] = "stop";

static const int DEFAULT_SPEED = 255;
char EXPECTED_HIGH_SPEED[50] = "255";
char EXPECTED_LOW_SPEED[50] = "200";
char EXPECTED_NO_SPEED[50] = "0";

int main() {
	int result;

	result = testWitness();
	if (0 < result) {
		return result;
	}

	result = testCommandBus();
	if (0 < result) {
		return result;
	}

	result = testBeeper();
	if (0 < result) {
		return result;
	}

	result = testControlSensor();
	if (0 < result) {
		return result;
	}

	result = testFaceSensor();
	if (0 < result) {
		return result;
	}

	// Clevercarino tests

	result = testInoBeeper();
	if (0 < result) {
		return result;
	}

	result = testInoControlSensor();
	if (0 < result) {
		return result;
	}

	result = testBlockedInoGroundFaceSensor();
	if (0 < result) {
		return result;
	}

	result = testFreeInoGroundFaceSensor();
	if (0 < result) {
		return result;
	}

	result = testInoTraction();
	if (0 < result) {
		return result;
	}

	return 0;
}

int testFaceSensor() {
	bool forcedIsFaceFree = true;
	int forcedBlockingDirections = 0b11111;
	faceSensor = new MockFaceSensor(&witness, forcedBlockingDirections,
			forcedIsFaceFree);
	if (false == faceSensor->isFaceFree()) {
		// Unexpected FaceSensor on checking if face is free
		return 111;
	}
	if (false
			== String::equal(witness.get(WITNESS_FACE), (char*) "isFaceFree",
					11)) {
		// Unexpected FaceSensor witness value after face is free
		return 222;
	}
	if (forcedBlockingDirections != faceSensor->getBlockedDirections()) {
		// Unexpected FaceSensor on checking blocked directions
		return 333;
	}
	if (false
			== String::equal(witness.get(WITNESS_FACE),
					(char*) "getBlockedDirections", 20)) {
		// Unexpected FaceSensor witness value after getting blocked directions
		return 444;
	}
	return 0;
}

int testControlSensor() {
	behavior forced = BH_BACK_RIGHT;
	sensor = new MockControlSensor(&witness, forced);
	behavior result = sensor->listen();
	if (false
			== String::equal(witness.get(WITNESS_CONTROL), (char*) "listen",
					5)) {
		// Unexpected ControlSensor witness value
		return 555;
	}
	if (forced != result) {
		// Unexpected ControlSensor listening result
		return 666;
	}
	return 0;
}

int testBeeper() {
	beeper = new MockBeeper(&witness);
	beeper->alarm();
	if (false
			== String::equal(witness.get(WITNESS_BEEPER), (char*) "alarm", 6)) {
		// Unexpected Beeper
		return 777;
	}
	beeper->beep();
	if (false
			== String::equal(witness.get(WITNESS_BEEPER), (char*) "beep", 5)) {
		// Unexpected Beeper
		return 888;
	}
	return 0;
}

int testCommandBus() {
	int speed = 255;
	CommandBus bus = CommandBus();
	Command *cmd;

	char eventOut[50];
	char expecteds[][10] = { "front", "left", "back", "backRight" };
	int expectedsIndex = 0;

	reviser = new MockReviser(&witness, BH_BACK);
	traction = new MockTraction(reviser, &witness);

	cmd = new TractionCommand(traction, &Traction::front, &Traction::back,
			speed);
	bus.append(cmd);
	cmd = new TractionCommand(traction, &Traction::left, &Traction::right,
			speed);
	bus.append(cmd);
	cmd = new TractionCommand(traction, &Traction::back, &Traction::front,
			speed);
	bus.append(cmd);
	cmd = new TractionCommand(traction, &Traction::backRight,
			&Traction::frontRight, speed);
	bus.append(cmd);

	while (!bus.isEmpty()) {
		cmd = bus.first();
		cmd->execute();
		String::copy(expecteds[expectedsIndex], eventOut, 5);
		if (false
				== String::equal(witness.get(WITNESS_TRACTION), eventOut, 5)) {
			// Unexpected CommandBus forwards
			return 999;
		}
		expectedsIndex++;
	}

	cmd = new TractionCommand(traction, &Traction::backRight,
			&Traction::frontRight, speed);
	bus.append(cmd);
	cmd = new TractionCommand(traction, &Traction::back, &Traction::front,
			speed);
	bus.append(cmd);
	cmd = new TractionCommand(traction, &Traction::left, &Traction::right,
			speed);
	bus.append(cmd);
	cmd = new TractionCommand(traction, &Traction::front, &Traction::back,
			speed);
	bus.append(cmd);

	expectedsIndex = 0;

	while (!bus.isEmpty()) {
		cmd = bus.last();
		cmd->execute();
		String::copy(expecteds[expectedsIndex], eventOut, 5);
		if (false
				== String::equal(witness.get(WITNESS_TRACTION), eventOut, 5)) {
			// Unexpected CommandBus backwards
			return 1000;
		}
		expectedsIndex++;
	}
	return 0;
}

int testWitness() {
	char event[50] = "Beeper";
	witness.set(WITNESS_BEEPER, event);
	if (false == String::equal(witness.get(WITNESS_BEEPER), event, 7)) {
		// Unexpected Witness
		return 123;
	}
	return 0;
}

// -----------------------------------------------------------------------------
// Clevercarino stuff
// -----------------------------------------------------------------------------

// Test functions

int testInoBeeper() {
	beeper = new MockBeeper(&witness);
	Beeper *inoBeeper = new InoBeeper(beepMillis, 2000, 100);
	inoBeeper->alarm();
	if (false
			== String::equal(witness.get(WITNESS_BEEPER), (char*) "alarm", 6)) {
		// Unexpected Beeper
		return 222777;
	}
	inoBeeper->beep();
	if (false
			== String::equal(witness.get(WITNESS_BEEPER), (char*) "beep", 5)) {
		// Unexpected Beeper
		return 222888;
	}
	return 0;
}

int testInoControlSensor() {
	behavior forced = BH_BACK_LEFT;
	inoControlTickBehavior = forced;
	sensor = new MockControlSensor(&witness, forced);
	ControlSensor *inoSensor = new InoControlSensor(remoteControlTick);
	behavior result = inoSensor->listen();
	if (false
			== String::equal(witness.get(WITNESS_CONTROL), (char*) "listen",
					5)) {
		// Unexpected ControlSensor witness value
		return 222555;
	}
	if (forced != result) {
		// Unexpected ControlSensor listening result
		return 222666;
	}
	return 0;
}

int testBlockedInoGroundFaceSensor() {
	return testInoGroundFaceSensor(0b11100, false);
}

int testFreeInoGroundFaceSensor() {
	return testInoGroundFaceSensor(0b00110, true);
}

int testInoGroundFaceSensor(int expectedBlocking, bool expectedFree) {
	inoForcedBlockingDirections = expectedBlocking;
	inoForcedIsFaceFree = expectedFree;
	faceSensor = new MockFaceSensor(&witness, inoForcedBlockingDirections,
			inoForcedIsFaceFree);
	FaceSensor *inoFaceSensor = new InoGroundFaceSensor(groundWatch);
	if (expectedFree != inoFaceSensor->isFaceFree()) {
		// Unexpected FaceSensor on checking if face is free
		return 222111;
	}
	if (expectedBlocking != inoFaceSensor->getBlockedDirections()) {
		// Unexpected FaceSensor on checking blocked directions
		return 222333;
	}
	if (false
			== String::equal(witness.get(WITNESS_FACE),
					(char*) "getBlockedDirections", 20)) {
		// Unexpected FaceSensor witness value after getting blocked directions
		return 222444;
	}
	return 0;
}

int testInoTraction() {
	reviser = new MockReviser(&witness, BH_FRONT_LEFT);
	Driver *inoDriver = new InoDriver(
			delayMillis,
			forwardLeft,
			rewindLeft,
			stopLeft,
			forwardRight,
			rewindRight,
			stopRight,
			setMotorSpeed,
			PERCENT_SPEED_DIFF
		);
	Nav *nav = new InoNav(1.0, 1.0, PERCENT_SPEED_DIFF);
	Traction *inoTraction = new InoTraction(inoDriver, reviser, nav, DRIVER_MOVEMENT_DURATION_MILLIS, SLIGHT_TURN_DEGREES);

	inoTraction->back(DEFAULT_SPEED);
	if (false
			== String::equal(witness.get(WITNESS_LEFT_WHEEL_STATUS),
					REWIND_WHEEL_STATUS, 4)) {
		return 333111;
	}
	if (false
			== String::equal(witness.get(WITNESS_RIGHT_WHEEL_STATUS),
					REWIND_WHEEL_STATUS, 4)) {
		return 333222;
	}
	if (false
			== String::equal(witness.get(WITNESS_LEFT_SPEED),
					EXPECTED_HIGH_SPEED, 3)) {
		return 333333;
	}
	if (false
			== String::equal(witness.get(WITNESS_RIGHT_SPEED),
					witness.get(WITNESS_LEFT_SPEED), 3)) {
		return 333444;
	}

	inoTraction->frontLeft(DEFAULT_SPEED);
	if (false
			== String::equal(witness.get(WITNESS_LEFT_WHEEL_STATUS),
					FORWARD_WHEEL_STATUS, 4)) {
		return 444111;
	}
	if (false
			== String::equal(witness.get(WITNESS_RIGHT_WHEEL_STATUS),
					FORWARD_WHEEL_STATUS, 4)) {
		return 444222;
	}
	if (false
			== String::equal(witness.get(WITNESS_LEFT_SPEED),
					EXPECTED_LOW_SPEED, 3)) {
		return 444333;
	}
	if (false
			== String::equal(witness.get(WITNESS_RIGHT_SPEED),
					EXPECTED_HIGH_SPEED, 3)) {
		return 444444;
	}

	inoTraction->right(DEFAULT_SPEED);
	if (false
			== String::equal(witness.get(WITNESS_LEFT_WHEEL_STATUS),
					FORWARD_WHEEL_STATUS, 4)) {
		return 555111;
	}
	if (false
			== String::equal(witness.get(WITNESS_RIGHT_WHEEL_STATUS),
					REWIND_WHEEL_STATUS, 4)) {
		return 555222;
	}
	if (false
			== String::equal(witness.get(WITNESS_LEFT_SPEED),
					EXPECTED_HIGH_SPEED, 3)) {
		return 555333;
	}
	if (false
			== String::equal(witness.get(WITNESS_RIGHT_SPEED),
					witness.get(WITNESS_LEFT_SPEED), 3)) {
		return 555444;
	}

	inoTraction->stop(0);
	if (false
			== String::equal(witness.get(WITNESS_LEFT_WHEEL_STATUS),
					STOP_WHEEL_STATUS, 4)) {
		return 666111;
	}
	if (false
			== String::equal(witness.get(WITNESS_RIGHT_WHEEL_STATUS),
					STOP_WHEEL_STATUS, 4)) {
		return 666222;
	}
	if (false
			== String::equal(witness.get(WITNESS_LEFT_SPEED),
					EXPECTED_NO_SPEED, 1)) {
		return 666333;
	}
	if (false
			== String::equal(witness.get(WITNESS_RIGHT_SPEED),
					witness.get(WITNESS_LEFT_SPEED), 1)) {
		return 666444;
	}

	return 0;
}

// Mocked Ino Capabilities implementing inoCapabilities.h

void forwardLeft() {
	witness.set(WITNESS_LEFT_WHEEL_STATUS, FORWARD_WHEEL_STATUS);
}

void rewindLeft() {
	witness.set(WITNESS_LEFT_WHEEL_STATUS, REWIND_WHEEL_STATUS);
}

void stopLeft() {
	witness.set(WITNESS_LEFT_WHEEL_STATUS, STOP_WHEEL_STATUS);
}

void forwardRight() {
	witness.set(WITNESS_RIGHT_WHEEL_STATUS, FORWARD_WHEEL_STATUS);
}

void rewindRight() {
	witness.set(WITNESS_RIGHT_WHEEL_STATUS, REWIND_WHEEL_STATUS);
}

void stopRight() {
	witness.set(WITNESS_RIGHT_WHEEL_STATUS, STOP_WHEEL_STATUS);
}

void setMotorSpeed(int speedLeft, int speedRight) {
	char speed[50];

	if (speedLeft == 0) {
		String::copy(EXPECTED_NO_SPEED, speed, 4);
	} else if (speedLeft < DEFAULT_SPEED) {
		String::copy(EXPECTED_LOW_SPEED, speed, 4);
	} else {
		String::copy(EXPECTED_HIGH_SPEED, speed, 4);
	}
	witness.set(WITNESS_LEFT_SPEED, speed);

	if (speedRight == 0) {
		String::copy(EXPECTED_NO_SPEED, speed, 4);
	} else if (speedRight < DEFAULT_SPEED) {
		String::copy(EXPECTED_LOW_SPEED, speed, 4);
	} else {
		String::copy(EXPECTED_HIGH_SPEED, speed, 4);
	}
	witness.set(WITNESS_RIGHT_SPEED, speed);
}

void beepMillis(int milliseconds) {
	if (milliseconds <= 1000) {
		beeper->beep();
	} else {
		beeper->alarm();
	}
}

int remoteControlTick() {
	return inoControlTickBehavior;
}

int groundWatch() {
	return inoForcedBlockingDirections;
}

void delayMillis(int milliseconds) {
	return;		// do nothing
}
