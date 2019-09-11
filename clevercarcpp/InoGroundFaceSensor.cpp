/*
 * InoGroundFaceSensor.cpp
 *
 *  Created on: Jul 20, 2019
 *      Author: jaume
 */

#include "InoGroundFaceSensor.h"

namespace clevercarino {

InoGroundFaceSensor::InoGroundFaceSensor(int (*groundWatchFunc)()) {
	this->groundWatchFunc = groundWatchFunc;
}

InoGroundFaceSensor::~InoGroundFaceSensor() {
}

int InoGroundFaceSensor::getBlockedDirections() {
	return this->groundWatchFunc();
}

bool InoGroundFaceSensor::isFaceFree() {
	int blockedDirections = this->getBlockedDirections();
	return 3 > this->countSetBits(blockedDirections);
}

int InoGroundFaceSensor::countSetBits(int number) {
    int count = 0;
    while (number) {
		number &= (number-1) ;
		count ++;
    }
    return count;
}

} /* namespace clevercarino */

