/*
 * InoBeeper.cpp
 *
 *  Created on: Jul 20, 2019
 *      Author: jaume
 */

#include "InoBeeper.h"

namespace clevercarino {

InoBeeper::InoBeeper(void (* beepMillisFunc)(int), int longer, int shorter) {
	this->beepMillisFunc = beepMillisFunc;
	this->longer = longer;
	this->shorter = shorter;
}

InoBeeper::~InoBeeper() {}

void InoBeeper::beep() {
	this->beepMillisFunc(this->shorter);
}

void InoBeeper::alarm() {
	this->beepMillisFunc(this->longer);
}

} /* namespace clevercarino */
