/*
 * InoSonicFaceSensor.cpp
 *
 *  Created on: Aug 22, 2019
 *      Author: jaume
 */

#include "InoSonicFaceSensor.h"

namespace clevercarino {

#define TURN_STEP_DEGREES		32
#define TURN_MIN_DEGREES		10
#define TURN_MAX_DEGREES		170
#define TURN_DEFAULT_DEGREES	90

InoSonicFaceSensor::InoSonicFaceSensor(bool (* sonicWatchFunc)(), void (* turnHeadDegreesFunc)(int)) {
	this->sonicWatchFunc = sonicWatchFunc;
	this->turnHeadDegreesFunc = turnHeadDegreesFunc;
	this->turnHeadDegreesFunc(TURN_DEFAULT_DEGREES);
}

InoSonicFaceSensor::~InoSonicFaceSensor() {}

bool InoSonicFaceSensor::isFaceFree() {
	if (this->sonicWatchFunc()) {
		return false;
	}
	return true;
}

int InoSonicFaceSensor::getBlockedDirections() {
	int blockedDirections = 0b00000;
	int degrees = TURN_MIN_DEGREES;

	this->turnHeadDegreesFunc(degrees);
	if (this->sonicWatchFunc()) {
		blockedDirections = blockedDirections | 0b00001;
	}

	degrees += TURN_STEP_DEGREES;

	this->turnHeadDegreesFunc(degrees);
	if (this->sonicWatchFunc()) {
		blockedDirections = blockedDirections | 0b00010;
	}

	degrees += TURN_STEP_DEGREES;

	this->turnHeadDegreesFunc(degrees);
	if (this->sonicWatchFunc()) {
		blockedDirections = blockedDirections | 0b00100;
	}

	degrees += TURN_STEP_DEGREES;

	this->turnHeadDegreesFunc(degrees);
	if (this->sonicWatchFunc()) {
		blockedDirections = blockedDirections | 0b01000;
	}

	degrees += TURN_STEP_DEGREES;

	this->turnHeadDegreesFunc(degrees);
	if (this->sonicWatchFunc()) {
		blockedDirections = blockedDirections | 0b10000;
	}

	this->turnHeadDegreesFunc(TURN_DEFAULT_DEGREES);

	return blockedDirections;
}

} /* namespace clevercarino */
