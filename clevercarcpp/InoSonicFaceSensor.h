/*
 * InoSonicFaceSensor.h
 *
 *  Created on: Aug 22, 2019
 *      Author: jaume
 */

#ifndef INOSONICFACESENSOR_H_
#define INOSONICFACESENSOR_H_

#include "FaceSensor.h"

namespace clevercarino {

class InoSonicFaceSensor: public FaceSensor {
private:
	bool (* sonicWatchFunc)();
	void (* turnHeadDegreesFunc)(int);

public:
	InoSonicFaceSensor(bool (* sonicWatchFunc)(), void (* turnHeadDegreesFunc)(int));

	~InoSonicFaceSensor();

	int getBlockedDirections();

	bool isFaceFree();
};

} /* namespace clevercarino */

#endif /* INOSONICFACESENSOR_H_ */
