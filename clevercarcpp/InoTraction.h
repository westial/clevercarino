/*
 * InoTraction.h
 *
 *  Created on: Jul 27, 2019
 *      Author: jaume
 */

#ifndef INOTRACTION_H_
#define INOTRACTION_H_

#include "Traction.h"
#include "Driver.h"
#include "Nav.h"

namespace clevercarino {

class InoTraction: public Traction {
private:
	Nav *nav;
	Driver *driver;
	int movementDuration;
	int slightTurnDegrees;

public:
	InoTraction(Driver *driver, Reviser *reviser, Nav *nav,
			int movementDuration, int slightTurnDegrees);

	~InoTraction();

	void front(int speed);

	void back(int speed);

	void right(int speed);

	void left(int speed);

	void frontRight(int speed);

	void frontLeft(int speed);

	void backRight(int speed);

	void backLeft(int speed);

	void stop(int speed);

	int getAbsoluteAngle();

	int getDistanceTraveled();

	void resetNavigation();

};

} /* namespace clevercarino */

#endif /* INOTRACTION_H_ */
