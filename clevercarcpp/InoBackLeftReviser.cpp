/*
 * InoBackLeftReviser.cpp
 *
 *  Created on: Aug 17, 2019
 *      Author: jaume
 */

#include "InoBackLeftReviser.h"

namespace clevercarino {

#define MOVEMENT_DURATION_MILLIS		250

InoBackLeftReviser::InoBackLeftReviser(Driver* driver) {
	this->driver = driver;
}

InoBackLeftReviser::~InoBackLeftReviser() {} /* namespace clevercarino */

void InoBackLeftReviser::away(int blockedDirections, int speed) {
	return this->driver->backLeft(speed, MOVEMENT_DURATION_MILLIS);
}
}
