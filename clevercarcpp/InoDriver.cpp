/*
 * InoDriver.cpp
 *
 *  Created on: Aug 22, 2019
 *      Author: jaume
 */

#include "InoDriver.h"

namespace clevercarino {

InoDriver::InoDriver(
		void (* delayMillisFunc)(int),
		void (*forwardLeftFunc)(),
		void (*rewindLeft)(),
		void (*stopLeft)(),
		void (*forwardRight)(),
		void (*rewindRight)(),
		void (*stopRight)(),
		void (*setMotorSpeed)(int, int),
		int percentSpeedDiff
	) {
	this->delayMillisFunc = delayMillisFunc;
	this->forwardLeftFunc = forwardLeftFunc;
	this->rewindLeftFunc = rewindLeft;
	this->stopLeftFunc = stopLeft;
	this->forwardRightFunc = forwardRight;
	this->rewindRightFunc = rewindRight;
	this->stopRightFunc = stopRight;
	this->setMotorSpeedFunc = setMotorSpeed;
	this->percentSpeedDiff = percentSpeedDiff;
}

InoDriver::~InoDriver() {
}

int InoDriver::lowerSpeed(int faster) {
	return faster - (faster * this->percentSpeedDiff) / 100;
}

void InoDriver::front(int speed, int duration) {
	this->forwardLeftFunc();
	this->forwardRightFunc();
	this->setMotorSpeedFunc(speed, speed);
	this->delayMillisFunc(duration);
}

void InoDriver::back(int speed, int duration) {
	this->rewindLeftFunc();
	this->rewindRightFunc();
	this->setMotorSpeedFunc(speed, speed);
	this->delayMillisFunc(duration);
}

void InoDriver::left(int speed, int duration) {
	this->forwardRightFunc();
	this->rewindLeftFunc();
	this->setMotorSpeedFunc(speed, speed);
	this->delayMillisFunc(duration);
}

void InoDriver::right(int speed, int duration) {
	this->forwardLeftFunc();
	this->rewindRightFunc();
	this->setMotorSpeedFunc(speed, speed);
	this->delayMillisFunc(duration);
}

void InoDriver::frontLeft(int speed, int duration) {
	this->forwardLeftFunc();
	this->forwardRightFunc();
	this->setMotorSpeedFunc(lowerSpeed(speed), speed);
	this->delayMillisFunc(duration);
}

void InoDriver::frontRight(int speed, int duration) {
	this->forwardLeftFunc();
	this->forwardRightFunc();
	this->setMotorSpeedFunc(speed, lowerSpeed(speed));
	this->delayMillisFunc(duration);
}

void InoDriver::backLeft(int speed, int duration) {
	this->rewindLeftFunc();
	this->rewindRightFunc();
	this->setMotorSpeedFunc(lowerSpeed(speed), speed);
	this->delayMillisFunc(duration);
}

void InoDriver::backRight(int speed, int duration) {
	this->rewindLeftFunc();
	this->rewindRightFunc();
	this->setMotorSpeedFunc(speed, lowerSpeed(speed));
	this->delayMillisFunc(duration);
}

void InoDriver::stop() {
	this->stopLeftFunc();
	this->stopRightFunc();
	this->setMotorSpeedFunc(0, 0);
}

} /* namespace clevercarino */
