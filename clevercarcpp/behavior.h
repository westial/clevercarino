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
 * File:   behavior.h
 * Author: Jaume Mila Bea <jaume@westial.com>
 *
 * Created on June 24, 2019, 2:52 PM
 */

#ifndef BEHAVIOR_H
#define BEHAVIOR_H

enum behavior {
    BH_AUTO = 1,
    BH_STOP = 2,

    BH_FRONT = 3,
    BH_FRONT_RIGHT = 4,
    BH_RIGHT = 5,
    BH_BACK_RIGHT = 6,
    BH_BACK = 7,
    BH_BACK_LEFT = 8,
    BH_LEFT = 9,
    BH_FRONT_LEFT = 10
};

#endif /* BEHAVIOR_H */

