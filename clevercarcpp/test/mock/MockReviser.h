/*
 * MockReviser.h
 *
 *  Created on: Jul 9, 2019
 *      Author: jaume
 */

#ifndef TEST_MOCK_MOCKREVISER_H_
#define TEST_MOCK_MOCKREVISER_H_

#include "../../Traction.h"
#include "../../Reviser.h"
#include "../../behavior.h"
#include "Witness.h"

class MockReviser: public Reviser{

private:
	Witness* witness;
	behavior forced;

public:

	MockReviser(Witness* witness, behavior forced);

	~MockReviser();

    void away(int blockedDirections, int speed);
};

#endif /* TEST_MOCK_MOCKREVISER_H_ */
