/*
 * MockReviser.cpp
 *
 *  Created on: Jun 26, 2019
 *      Author: jaume
 */

#include "MockReviser.h"

MockReviser::MockReviser(Witness* witness, behavior forced) {
	this->witness = witness;
	this->forced = forced;
}

MockReviser::~MockReviser() {
	delete [] this->witness;
}

void MockReviser::away(int blockedDirections, int speed) {
	this->witness->set(WITNESS_TRACTION, (char*) "away");
	this->witness->set(WITNESS_REVISE, (char*) "forced");
}


