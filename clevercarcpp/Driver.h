/*
 * Driver.h
 *
 *  Created on: Aug 22, 2019
 *      Author: jaume
 */

#ifndef DRIVER_H_
#define DRIVER_H_


class Driver {
public:
	virtual ~Driver() {};

    virtual void front(int speed, int duration) = 0;

    virtual void back(int speed, int duration) = 0;

    virtual void right(int speed, int duration) = 0;

    virtual void left(int speed, int duration) = 0;

    virtual void frontRight(int speed, int duration) = 0;

    virtual void frontLeft(int speed, int duration) = 0;

    virtual void backRight(int speed, int duration) = 0;

    virtual void backLeft(int speed, int duration) = 0;

    virtual void stop() = 0;
};


#endif /* DRIVER_H_ */
