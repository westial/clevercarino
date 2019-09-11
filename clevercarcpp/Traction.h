/*
 * Copyright (C) 2019 Jaume Mila Bea <jaume@westial.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * File:   Traction.h
 * Author: Jaume Mila Bea <jaume@westial.com>
 *
 * Created on June 24, 2019, 1:31 PM
 */

#ifndef TRACTION_H
#define TRACTION_H

#include "faceDirection.h"
#include "Reviser.h"

class Traction {

private:
	Reviser* reviser;

public:
	Traction(Reviser* reviser) {
		this->reviser = reviser;
	}

	virtual ~Traction() {};

    virtual void front(int speed) = 0;

    virtual void back(int speed) = 0;

    virtual void right(int speed) = 0;

    virtual void left(int speed) = 0;

    virtual void frontRight(int speed) = 0;

    virtual void frontLeft(int speed) = 0;

    virtual void backRight(int speed) = 0;

    virtual void backLeft(int speed) = 0;

    virtual void stop(int speed) = 0;

    virtual int getAbsoluteAngle() = 0;

    virtual int getDistanceTraveled() = 0;

    virtual void resetNavigation() = 0;

    void revise(int blockedDirections, int speed) {
    	this->reviser->away(blockedDirections, speed);
    }
};

#endif /* TRACTION_H */

