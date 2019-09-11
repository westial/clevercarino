/*
 * MockTraction.h
 *
 *  Created on: Jun 26, 2019
 *      Author: jaume
 */

#ifndef TEST_MOCK_MOCKTRACTION_H_
#define TEST_MOCK_MOCKTRACTION_H_

#include "../../Traction.h"
#include "Witness.h"

class MockTraction: public Traction {
private:
	Witness* witness;

public:
	MockTraction(Reviser* reviser, Witness* witness);

	~MockTraction();

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

#endif /* TEST_MOCK_MOCKTRACTION_H_ */
