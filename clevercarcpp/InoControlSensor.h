/*
 * InoControlSensor.h
 *
 *  Created on: Jul 20, 2019
 *      Author: jaume
 */

#ifndef INOCONTROLSENSOR_H_
#define INOCONTROLSENSOR_H_

#include "ControlSensor.h"

namespace clevercarino {

class InoControlSensor: public ControlSensor {
private:
	int (* remoteControlTickFunc)();

public:
	InoControlSensor(int (* remoteControlTickFunc)());

	~InoControlSensor();

	behavior listen();

};

} /* namespace clevercarino */

#endif /* INOCONTROLSENSOR_H_ */
