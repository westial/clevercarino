/*
 * InoGroundFaceSensor.h
 *
 *  Created on: Jul 20, 2019
 *      Author: jaume
 */

#ifndef INOGROUNDFACESENSOR_H_
#define INOGROUNDFACESENSOR_H_

#include "FaceSensor.h"

namespace clevercarino {

class InoGroundFaceSensor: public FaceSensor {
private:
	int (* groundWatchFunc)();
	int countSetBits(int number);
public:
	InoGroundFaceSensor(int (* groundWatch)());

	~InoGroundFaceSensor();

	int getBlockedDirections();

	bool isFaceFree();
};

} /* namespace clevercarino */

#endif /* INOGROUNDFACESENSOR_H_ */
