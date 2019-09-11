/*
 * String.h
 *
 *  Created on: Jun 30, 2019
 *      Author: jaume
 */

#ifndef UTIL_STRING_H_
#define UTIL_STRING_H_

class String {
public:
	String();
	~String();
	static void copy(char* source, char* destination, int size);
	static bool equal(char* sample1, char* sample2, int charsToCompare);
};

#endif /* UTIL_STRING_H_ */
