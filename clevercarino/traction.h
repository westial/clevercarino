/*
 * traction.h
 *
 *  Created on: Aug 26, 2019
 *      Author: jaume
 */

#ifndef CONF_D_TRACTION_H_
#define CONF_D_TRACTION_H_

/* Declare L298N Dual H-Bridge Motor Controller directly since there is not a library to load.*/
// Define L298N Dual H-Bridge Motor Controller Pins
#define dir1PinR            2    	// Motor direction
#define dir2PinR            4    	// Motor direction
#define speedPinR           5      // Needs to be a PWM pin to be able to control motor speed

#define dir1PinL            7    	// Motor direction
#define dir2PinL            8   	// Motor direction
#define speedPinL           6      // Needs to be a PWM pin to be able to control motor speed

#define AUTO_SPEED                120
#define DEFAULT_SPEED             255
#define PERCENT_SPEED_DIFF        50
#define DRIVER_REQUEST_DURATION   8
#define SLIGHT_TURN_DEGREES       20

/*
 * When speed is as 255 and duration is as 1 millisecond the car turns 0.42 degrees.
 * Proportionally, the factor to multiply any speed is as follows.
 */
#define TURNING_DEGREES_FACTOR    0.001647059

/*
 * When speed is as 255 and duration is as 1 millisecond the car travels 0.187 cm.
 * Proportionally, the factor to multiply any speed is as follows.
 */
#define SPEED_CONVERTER_FACTOR    0.000733333

#endif /* CONF_D_TRACTION_H_ */
