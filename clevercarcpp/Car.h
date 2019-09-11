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
 * File:   Car.h
 * Author: Jaume Mila Bea <jaume@westial.com>
 *
 * Created on June 24, 2019, 4:25 PM
 */

#ifndef CAR_H
#define CAR_H

#include "Command.h"
#include "behavior.h"


class Car {
public:
    virtual void run(behavior what) = 0;
    virtual Command* getState() = 0;
    virtual ~Car() {};
};

#endif /* CAR_H */

