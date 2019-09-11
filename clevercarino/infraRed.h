/*
 * infrared.h
 *
 *  Created on: Aug 26, 2019
 *      Author: jaume
 */

#ifndef INFRARED_H_
#define INFRARED_H_

#define MANUAL_MODE_TICK_MILLIS   100

#define IR_PIN    3 	// IR receiver Signal pin connect to Arduino

#define IR_VALUE_0            0xFFFF9867
#define IR_VALUE_1            0xFFFFA25D
#define IR_VALUE_2            0x629D
#define IR_VALUE_3            0xFFFFE21D
#define IR_VALUE_4            0x22DD
#define IR_VALUE_5            0x2FD
#define IR_VALUE_6            0xFFFFC23D
#define IR_VALUE_7            0xFFFFE01F
#define IR_VALUE_8            0xFFFFA857
#define IR_VALUE_9            0xFFFF906F

#define IR_VALUE_REDIAL       0xFFFFB04F
#define IR_VALUE_ASTERISK     0x6897

#define IR_VALUE_FRONT        0x18E7
#define IR_VALUE_LEFT         0x10EF
#define IR_VALUE_BACK         0x4AB5
#define IR_VALUE_RIGHT        0x5AA5

#define IR_VALUE_OK           0x38C7


#endif /* INFRARED_H_ */
