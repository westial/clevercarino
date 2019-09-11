/*
 * String.cpp
 *
 *  Created on: Jun 30, 2019
 *      Author: jaume
 */

#include "String.h"

String::String() {}

String::~String() {}

void String::copy(char* source, char* destination, int size) {
	for (int i = 0; i < size; i ++) {
		destination[i] = source[i];
	}
}

bool String::equal(char* sample1, char* sample2, int size) {
	for (int i = 0; i < size; i ++) {
		if (sample1[i] != sample2[i]) {
			return false;
		}
	}
	return true;
}

