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
 * File:   faceDirection.h
 * Author: Jaume Mila Bea <jaume@westial.com>
 *
 * Created on June 24, 2019, 2:28 PM
 */

#ifndef FACEDIRECTION_H
#define FACEDIRECTION_H

enum faceDirection {
    FACE_RIGHT = 		1 << 0,		// 00001
    FACE_FRONT_RIGHT = 	1 << 1,		// 00010
    FACE_FRONT = 		1 << 2,		// 00100
    FACE_FRONT_LEFT = 	1 << 3,		// 01000
    FACE_LEFT = 		1 << 4		// 10000
};

#endif /* FACEDIRECTION_H */

