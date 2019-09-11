/*
 * Nav.h
 *
 *  Created on: Aug 24, 2019
 *      Author: jaume
 */

#ifndef NAV_H_
#define NAV_H_

class Nav {
public:
	virtual ~Nav() {};

	virtual int getDistance() = 0;

	virtual int getAngle() = 0;

	virtual void turn(int speed, int duration) = 0;

	virtual void move(int degrees, int speed, int duration) = 0;

	virtual void reset() = 0;
};

#endif /* NAV_H_ */
