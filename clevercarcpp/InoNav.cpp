/*
 * InoNav.cpp
 *
 *  Created on: Aug 24, 2019
 *      Author: jaume
 */

#include "InoNav.h"

namespace clevercarino {

InoNav::InoNav(double turningDegreesFactor, double movingDistanceFactor, int wheelPercentSpeedDiff) {
	this->turningDegreesFactor = turningDegreesFactor;
	this->speedConverterFactor = movingDistanceFactor;
	this->wheelPercentSpeedDiff = wheelPercentSpeedDiff;
}

InoNav::~InoNav() {}

void InoNav::move(int degrees, int speed, int duration) {
	const double straightDistance = this->convertSpeed(speed * duration);
	if (degrees != 0) {
		this->distance += this->calculateTurningDistance(this->wheelPercentSpeedDiff, straightDistance);
	} else {
		this->distance += straightDistance;
	}
	this->angle += degrees;
}

void InoNav::turn(int speed, int duration) {
	this->angle += this->calculateTurningDegrees(speed, duration);
}

int InoNav::calculateTurningDegrees(int speed, int duration) {
	return speed * this->turningDegreesFactor * duration;
}

int InoNav::calculateTurningDistance(int wheelPercentSpeedDiff, double distance) {
	const double wheelTurningFactor = 1 + (wheelPercentSpeedDiff / 100.0);
	return distance / wheelTurningFactor;
}

int InoNav::convertSpeed(int speed) {
	return speed * speedConverterFactor;
}

int InoNav::getAngle() {
	return this->angle;
}

int InoNav::getDistance() {
	return this->distance;
}

void InoNav::reset() {
	this->angle = 0;
	this->distance = 0;
}

} /* namespace clevercarino */
