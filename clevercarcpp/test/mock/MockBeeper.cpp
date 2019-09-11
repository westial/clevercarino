/*
 * MockBeeper.cpp
 *
 *  Created on: Jun 25, 2019
 *      Author: jaume
 */

#include "MockBeeper.h"

MockBeeper::~MockBeeper() {
	delete [] this->witness;
}

MockBeeper::MockBeeper(Witness* witness) {
	this->witness = witness;
}

void MockBeeper::beep() {
	this->witness->set(WITNESS_BEEPER, (char*) "beep");
}


void MockBeeper::alarm() {
	this->witness->set(WITNESS_BEEPER, (char*) "alarm");
}
