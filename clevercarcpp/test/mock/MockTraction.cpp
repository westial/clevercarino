/*
 * MockTraction.cpp
 *
 *  Created on: Jun 26, 2019
 *      Author: jaume
 */

#include "MockTraction.h"

MockTraction::~MockTraction() {
	delete [] this->witness;
}

MockTraction::MockTraction(Reviser* reviser, Witness* witness): Traction(reviser) {
	this->witness = witness;
};

void MockTraction::front(int speed) {
	this->witness->set(WITNESS_TRACTION, (char*) "front");
};

void MockTraction::back(int speed) {
	this->witness->set(WITNESS_TRACTION, (char*) "back");
};

void MockTraction::right(int speed) {
	this->witness->set(WITNESS_TRACTION, (char*) "right");
};

void MockTraction::left(int speed) {
	this->witness->set(WITNESS_TRACTION, (char*) "left");
};

void MockTraction::frontRight(int speed) {
	this->witness->set(WITNESS_TRACTION, (char*) "frontRight");
};

void MockTraction::frontLeft(int speed) {
	this->witness->set(WITNESS_TRACTION, (char*) "frontLeft");
};

void MockTraction::backRight(int speed) {
	this->witness->set(WITNESS_TRACTION, (char*) "backRight");
};

void MockTraction::backLeft(int speed) {
	this->witness->set(WITNESS_TRACTION, (char*) "backLeft");
};

void MockTraction::stop(int speed) {
	this->witness->set(WITNESS_TRACTION, (char*) "stop");
};

int MockTraction::getAbsoluteAngle() {
	return 0;
}

int MockTraction::getDistanceTraveled() {
	return 0;
}

void MockTraction::resetNavigation() {
	return;
}
