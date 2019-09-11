/*
 * Witness.cpp
 *
 *  Created on: Jun 28, 2019
 *      Author: jaume
 */
#include "Witness.h"
#include "../util/String.h"

Witness::Witness() {}

Witness::~Witness() {}

void Witness::set(whichWitness which, char* event) {
	switch (which) {
	case WITNESS_BEEPER:
		String::copy(event, this->beeper, MAX_LENGTH);
		break;
	case WITNESS_CONTROL:
		String::copy(event, this->control, MAX_LENGTH);
		break;
	case WITNESS_FACE:
		String::copy(event, this->face, MAX_LENGTH);
		break;
	case WITNESS_TRACTION:
		String::copy(event, this->traction, MAX_LENGTH);
		break;
	case WITNESS_LEFT_WHEEL_STATUS:
		String::copy(event, this->leftWheelStatus, MAX_LENGTH);
		break;
	case WITNESS_RIGHT_WHEEL_STATUS:
		String::copy(event, this->rightWheelStatus, MAX_LENGTH);
		break;
	case WITNESS_LEFT_SPEED:
		String::copy(event, this->leftSpeed, MAX_LENGTH);
		break;
	case WITNESS_RIGHT_SPEED:
		String::copy(event, this->rightSpeed, MAX_LENGTH);
		break;
	case WITNESS_REVISE:
		String::copy(event, this->revise, MAX_LENGTH);
		break;
	}
}

char* Witness::get(whichWitness which) {
	switch (which) {
	case WITNESS_BEEPER:
		return this->beeper;
	case WITNESS_CONTROL:
		return this->control;
	case WITNESS_FACE:
		return this->face;
	case WITNESS_TRACTION:
		return this->traction;
	case WITNESS_LEFT_WHEEL_STATUS:
		return this->leftWheelStatus;
	case WITNESS_RIGHT_WHEEL_STATUS:
		return this->rightWheelStatus;
	case WITNESS_LEFT_SPEED:
		return this->leftSpeed;
	case WITNESS_RIGHT_SPEED:
		return this->rightSpeed;
	case WITNESS_REVISE:
		return this->revise;
	}
	return nullptr;
}
