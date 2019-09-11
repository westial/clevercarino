/*
 * MockControlSensor.h
 *
 *  Created on: Jun 25, 2019
 *      Author: jaume
 */

#ifndef TEST_MOCK_MOCKCONTROLSENSOR_H_
#define TEST_MOCK_MOCKCONTROLSENSOR_H_

#include "Witness.h"
#include "../../behavior.h"
#include "../../ControlSensor.h"

class MockControlSensor: public ControlSensor {
private:
	Witness* witness;
	behavior forced;
public:

	~MockControlSensor();

	MockControlSensor(Witness* witness, behavior forced);

	behavior listen();
};

#endif /* TEST_MOCK_MOCKCONTROLSENSOR_H_ */
