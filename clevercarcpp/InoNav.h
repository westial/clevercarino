/*
 * InoNav.h
 *
 *  Created on: Aug 24, 2019
 *      Author: jaume
 */

#ifndef INONAV_H_
#define INONAV_H_

#include "Nav.h"

namespace clevercarino {

class InoNav: public Nav {
private:
	int distance = 0;
	int angle = 0;

	double turningDegreesFactor;

	double speedConverterFactor;

	int wheelPercentSpeedDiff;

	int calculateTurningDegrees(int speed, int duration);

	/**
	 * Calculate the distance when car is slightly turning
	 * and with one side wheels slower than other one.
	 */
	int calculateTurningDistance(int wheelPercentSpeedDiff, double distance);

	int calculateMovingDistance(int speed, int duration);

	/**
	 * Convert ambiguous "byte" speed into centimeters/second speed value
	 */
	int convertSpeed(int speed);

public:
	InoNav(double degreesFactor, double distanceFactor, int wheelPercentSpeedDiff);

	~InoNav();

	int getAngle();

	int getDistance();

	void turn(int speed, int duration);

	void move(int degrees, int speed, int duration);

	void reset();
};

} /* namespace clevercarino */

#endif /* INONAV_H_ */
