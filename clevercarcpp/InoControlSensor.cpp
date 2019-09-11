/*
 * InoControlSensor.cpp
 *
 *  Created on: Jul 20, 2019
 *      Author: jaume
 */

#include "InoControlSensor.h"

namespace clevercarino {

InoControlSensor::InoControlSensor(int (* remoteControlTickFunc)()) {
	this->remoteControlTickFunc = remoteControlTickFunc;
}

behavior InoControlSensor::listen() {
	// TODO: convert remote control hex number to behavior
	return static_cast<behavior>(this->remoteControlTickFunc());
}

InoControlSensor::~InoControlSensor() {}

}


/* namespace clevercarino */
