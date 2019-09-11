/*
 * InoTraction.cpp
 *
 *  Created on: Jul 27, 2019
 *      Author: jaume
 */

#include "InoTraction.h"

namespace clevercarino {

InoTraction::InoTraction(Driver *driver, Reviser *reviser, Nav *nav,
		int movementDuration, int slightTurnDegrees) :
		Traction(reviser) {
	this->nav = nav;
	this->driver = driver;
	this->movementDuration = movementDuration;
	this->slightTurnDegrees = slightTurnDegrees;
}

InoTraction::~InoTraction() {
}

void InoTraction::front(int speed) {
	this->driver->front(speed, this->movementDuration);
	this->nav->move(0, speed, this->movementDuration);
}

void InoTraction::back(int speed) {
	this->driver->back(speed, this->movementDuration);
	this->nav->move(0, speed * (-1), this->movementDuration);
}

void InoTraction::left(int speed) {
	this->driver->left(speed, this->movementDuration);
	this->nav->turn(speed * (-1), this->movementDuration);
}

void InoTraction::right(int speed) {
	this->driver->right(speed, this->movementDuration);
	this->nav->turn(speed, this->movementDuration);
}

void InoTraction::frontLeft(int speed) {
	this->driver->frontLeft(speed, this->movementDuration);
	this->nav->move(this->slightTurnDegrees * (-1), speed, this->movementDuration);
}

void InoTraction::frontRight(int speed) {
	this->driver->frontRight(speed, this->movementDuration);
	this->nav->move(this->slightTurnDegrees, speed, this->movementDuration);
}

void InoTraction::backLeft(int speed) {
	this->driver->backLeft(speed, this->movementDuration);
	this->nav->move(this->slightTurnDegrees, speed * (-1), this->movementDuration);
}

void InoTraction::backRight(int speed) {
	this->driver->backRight(speed, this->movementDuration);
	this->nav->move(this->slightTurnDegrees * (-1), speed * (-1), this->movementDuration);
}

void InoTraction::stop(int speed) {
	this->driver->stop();
}

int InoTraction::getAbsoluteAngle() {
	return this->nav->getAngle();
}

int InoTraction::getDistanceTraveled() {
	return this->nav->getDistance();
}

void InoTraction::resetNavigation() {
	this->nav->reset();
}

} /* namespace clevercarino */
