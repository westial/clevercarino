/*
 * InoBackLeftReviser.h
 *
 *  Created on: Aug 17, 2019
 *      Author: jaume
 */

#ifndef INOBACKLEFTREVISER_H_
#define INOBACKLEFTREVISER_H_

#include "Reviser.h"
#include "Driver.h"

namespace clevercarino {

class InoBackLeftReviser: public Reviser {
private:
	Driver* driver;

public:
	InoBackLeftReviser(Driver* driver);

	~InoBackLeftReviser();

	void away(int blockedDirections, int speed);
};

} /* namespace clevercarino */

#endif /* INOBACKLEFTREVISER_H_ */
