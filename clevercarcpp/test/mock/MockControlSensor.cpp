/*
 * MockControlSensor.cpp
 *
 *  Created on: Jun 25, 2019
 *      Author: jaume
 */

#include "MockControlSensor.h"

MockControlSensor::~MockControlSensor() {
	delete [] this->witness;
}

MockControlSensor::MockControlSensor(Witness* witness, behavior forced)
{
	this->witness = witness;
	this->forced = forced;
}

behavior MockControlSensor::listen()
{
	this->witness->set(WITNESS_CONTROL, (char*) "listen");
	return this->forced;
}

