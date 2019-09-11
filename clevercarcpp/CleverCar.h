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
 * File:   CleverCar.h
 * Author: Jaume Mila Bea <jaume@westial.com>
 *
 * Created on June 24, 2019, 4:29 PM
 */

#ifndef CLEVERCAR_H
#define CLEVERCAR_H

#include "Car.h"
#include "CommandBus.h"
#include "TractionCommand.h"
#include "behavior.h"
#include "Beeper.h"
#include "ControlSensor.h"
#include "FaceSensor.h"
#include "Traction.h"

class CleverCar : public Car {
private:

	CommandBus* play;
	CommandBus* history;
	Command* state;

    Beeper* beeper;
    ControlSensor* control;
    FaceSensor* face;
    FaceSensor* ground;
    Traction* traction;
    int lowSpeed;
    int highSpeed;

    void setAuto();

    void setStop();

    void setDirection(behavior direction);

public:

    CleverCar(
            Beeper* beeper,
            ControlSensor* control,
            FaceSensor* face,
            FaceSensor* ground,
            Traction* traction,
            int lowSpeed,
            int highSpeed,
			int maxCommandsBuffer
            );

    ~CleverCar();

    void run(behavior what);

    Command* getState();
};

#endif /* CLEVERCAR_H */

