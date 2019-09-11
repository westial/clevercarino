/*
 * MockBeeper.h
 *
 *  Created on: Jun 25, 2019
 *      Author: jaume
 */

#ifndef TEST_MOCK_MOCKBEEPER_H_
#define TEST_MOCK_MOCKBEEPER_H_

#include "../../Beeper.h"
#include "Witness.h"

class MockBeeper: public Beeper {
private:
	Witness* witness;

public:

	MockBeeper(Witness* witness);

	~MockBeeper();

	void beep();

	void alarm();
};

#endif /* TEST_MOCK_MOCKBEEPER_H_ */
