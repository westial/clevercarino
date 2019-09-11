/*
 * InoBeeper.h
 *
 *  Created on: Jul 20, 2019
 *      Author: jaume
 */

#ifndef INOBEEPER_H_
#define INOBEEPER_H_

#include "Beeper.h"

namespace clevercarino {

class InoBeeper: public Beeper {
private:
	void (* beepMillisFunc)(int);

	int longer;
	int shorter;

public:
	InoBeeper(void (* beepMillisFunc)(int), int longer, int shorter);

	~InoBeeper();

	void beep();

	void alarm();
};

} /* namespace clevercarino */

#endif /* INOBEEPER_H_ */
