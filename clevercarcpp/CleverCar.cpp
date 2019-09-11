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
 * File:   CleverCar.cpp
 * Author: Jaume Mila Bea <jaume@westial.com>
 *
 * Created on June 24, 2019, 4:50 PM
 */
#include "CleverCar.h"
#include "TractionCommand.h"
#include "CommandBus.h"
#include "Beeper.h"
#include "ControlSensor.h"
#include "FaceSensor.h"
#include "Traction.h"

CleverCar::~CleverCar() {
	delete [] this->beeper;
	delete [] this->control;
	delete [] this->face;
	delete [] this->ground;
	delete [] this->traction;
	delete [] this->play;
	delete [] this->history;
	delete [] this->state;
};

CleverCar::CleverCar(
        Beeper* beeper,
        ControlSensor* control,
        FaceSensor* face,
        FaceSensor* ground,
        Traction* traction,
        int lowSpeed,
        int highSpeed,
		int maxCommandsBuffer
		){

    this->beeper = beeper;
    this->control = control;
    this->face = face;
    this->ground = ground;
    this->traction = traction;
    this->lowSpeed = lowSpeed;
    this->highSpeed = highSpeed;

    this->play = new CommandBus();
    this->history = new CommandBus();

    this->state = nullptr;
};

Command* CleverCar::getState() {
    return this->state;
};

void CleverCar::setAuto() {
	this->setDirection(BH_FRONT);
};

void CleverCar::setStop() {
	this->play->clean();
    this->traction->stop(0);
};

void CleverCar::setDirection(behavior direction) {
    switch (direction) {
        case BH_FRONT:
            this->play->append(new TractionCommand(this->traction, &Traction::front, &Traction::back, this->lowSpeed));
            break;
        case BH_FRONT_RIGHT:
        	this->play->append(new TractionCommand(this->traction, &Traction::frontRight, &Traction::backRight, this->lowSpeed));
            break;
        case BH_RIGHT:
        	this->play->append(new TractionCommand(this->traction, &Traction::right, &Traction::left, this->lowSpeed));
            break;
        case BH_BACK_RIGHT:
        	this->play->append(new TractionCommand(this->traction, &Traction::backRight, &Traction::backLeft, this->lowSpeed));
            break;
        case BH_BACK:
        	this->play->append(new TractionCommand(this->traction, &Traction::back, &Traction::front, this->lowSpeed));
            break;
        case BH_BACK_LEFT:
        	this->play->append(new TractionCommand(this->traction, &Traction::backLeft, &Traction::backRight, this->lowSpeed));
            break;
        case BH_LEFT:
        	this->play->append(new TractionCommand(this->traction, &Traction::left, &Traction::right, this->lowSpeed));
            break;
        case BH_FRONT_LEFT:
        	this->play->append(new TractionCommand(this->traction, &Traction::frontLeft, &Traction::frontRight, this->lowSpeed));
            break;
        default:
        	this->play->append(new TractionCommand(this->traction, &Traction::stop, &Traction::stop, 0));
        	this->beeper->alarm();
    }
};

void CleverCar::run(behavior what) {

    switch (what) {
        case BH_AUTO:
            setAuto();
            break;
        case BH_STOP:
            setStop();
            break;
        default:
            setDirection(what);
    }

    while (!this->play->isEmpty())
    {
    	this->state = this->play->first();
    	this->state->execute();
    	if (false == this->ground->isFaceFree() || false == this->face->isFaceFree()) {
    		this->setStop();
    		int allBlocked = this->ground->getBlockedDirections() | this->face->getBlockedDirections();
    		this->traction->revise(allBlocked, this->lowSpeed);
    		this->setAuto();
    	}
    }
};

