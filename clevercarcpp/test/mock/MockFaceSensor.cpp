/*
 * MockFaceSensor.cpp
 *
 *  Created on: Jun 25, 2019
 *      Author: jaume
 */

#include "MockFaceSensor.h"

MockFaceSensor::~MockFaceSensor() {
	delete [] this->witness;
}

MockFaceSensor::MockFaceSensor(Witness* witness, int forced, bool isFaceFreeForced) {
	this->witness = witness;
	this->forced = forced;
	this->isFaceFreeForced = isFaceFreeForced;
}

int MockFaceSensor::getBlockedDirections()
{
	this->witness->set(WITNESS_FACE, (char*) "getBlockedDirections");
	return this->forced;
}

bool MockFaceSensor::isFaceFree() {
	this->witness->set(WITNESS_FACE, (char*) "isFaceFree");
	return this->isFaceFreeForced;
}

