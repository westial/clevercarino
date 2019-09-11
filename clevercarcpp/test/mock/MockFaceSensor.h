/*
 * MockFaceSensor.h
 *
 *  Created on: Jun 25, 2019
 *      Author: jaume
 */

#ifndef TEST_MOCK_MOCKFACESENSOR_H_
#define TEST_MOCK_MOCKFACESENSOR_H_

#include "../../FaceSensor.h"
#include "../../faceDirection.h"
#include "Witness.h"

class MockFaceSensor: public FaceSensor {
private:
	Witness* witness;
	int forced;
	bool isFaceFreeForced;

public:

	~MockFaceSensor();

	MockFaceSensor(Witness* witness, int forced, bool isFaceFreeForced);

	int getBlockedDirections();

	bool isFaceFree();
};

#endif /* TEST_MOCK_MOCKFACESENSOR_H_ */
