/*
 * Witness.h
 *
 *  Created on: Jun 28, 2019
 *      Author: jaume
 */

#ifndef TEST_MOCK_WITNESS_H_
#define TEST_MOCK_WITNESS_H_

enum whichWitness {
	WITNESS_BEEPER = 1,
	WITNESS_CONTROL = 2,
	WITNESS_FACE = 3,
	WITNESS_TRACTION = 4,
	WITNESS_LEFT_WHEEL_STATUS = 5,
	WITNESS_RIGHT_WHEEL_STATUS = 6,
	WITNESS_LEFT_SPEED = 7,
	WITNESS_RIGHT_SPEED = 8,
	WITNESS_REVISE = 9
};

class Witness {
private:
	static const int MAX_LENGTH = 50;
	char beeper[MAX_LENGTH];
	char control[MAX_LENGTH];
	char face[MAX_LENGTH];
	char traction[MAX_LENGTH];
	char leftWheelStatus[MAX_LENGTH];
	char rightWheelStatus[MAX_LENGTH];
	char leftSpeed[MAX_LENGTH];
	char rightSpeed[MAX_LENGTH];
	char revise[MAX_LENGTH];

public:
	Witness();

	~Witness();

	void set(whichWitness which, char* event);

	char* get(whichWitness which);
};

#endif /* TEST_MOCK_WITNESS_H_ */
