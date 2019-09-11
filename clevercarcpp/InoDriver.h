/*
 * InoDriver.h
 *
 *  Created on: Aug 22, 2019
 *      Author: jaume
 */

#ifndef INODRIVER_H_
#define INODRIVER_H_

#include "Driver.h"

namespace clevercarino {

class InoDriver: public Driver {
private:
	void (* delayMillisFunc)(int);
	void (*forwardLeftFunc)();
	void (*rewindLeftFunc)();
	void (*stopLeftFunc)();
	void (*forwardRightFunc)();
	void (*rewindRightFunc)();
	void (*stopRightFunc)();
	void (*setMotorSpeedFunc)(int, int);
	int percentSpeedDiff;
	int lowerSpeed(int faster);
public:
	InoDriver(
			void (* delayMillisFunc)(int),
			void (*forwardLeftFunc)(),
			void (*rewindLeft)(),
			void (*stopLeft)(),
			void (*forwardRight)(),
			void (*rewindRight)(),
			void (*stopRight)(),
			void (*setMotorSpeed)(int, int),
			int percentSpeedDiff
	);

	~InoDriver();

	void front(int speed, int duration);

	void back(int speed, int duration);

	void right(int speed, int duration);

	void left(int speed, int duration);

	void frontRight(int speed, int duration);

	void frontLeft(int speed, int duration);

	void backRight(int speed, int duration);

	void backLeft(int speed, int duration);

	void stop();
};

} /* namespace clevercarino */

#endif /* INODRIVER_H_ */
