/*===============================

	# LineCruiser
	
	This module allows you to make a robot follow a line
	
	## Resources used (by this and its children):
	
	1. P1.2 for the Motor-1 Forward FPWM output
	2. P1.3 for the Motor-1 Reverse FPWM output
	3. P2.4 for the Motor-2 Forward FPWM output
	4. P2.5 for the Motor-2 Reverse FPWM output
	5. Timer A0 to generate FPWM signals to the motors.
	6. Timer A2 to generate FPWM signals to the motors.
	6. P2.0 for the Motor-1 Encoder
	7. P2.2 for the Motor-2 Encoder
	8. Timer A1 to setup the Velocity Calculations.
	9. port 3.0(SDA) & port 3.1（SCL)
    10. power pins 5V and GND
    11. UCSI(B0)

	
	# Requirements
	
	1. DiffDriver Module
	2. LineSensorDriver Module
	3. Scheduler Module
	
===============================*/
#ifndef LINE_CRUISER_H
#define LINE_CRUISER_H

/*=======
Includes
========*/

/*=======
Macros
========*/
// Tightest curve radius in cm
#define SHARPEST_CURVE 15
// CRUISE_KP + CRUISE_KD = 1
#define CRUISE_KD 0.7
#define CRUISE_KP 0.3
// Number between 0 and 1 to tell how much to slow down in tightening curves. 0 means never slows down. 1 means full stop on tightest curve
#define CORNERING_D_BRAKE_FACTOR 0.9
// Number between 0 and 1 to tell how much to slow down in any curve. 0 means never slows down. 1 means full stop on tightest curve
#define CORNERING_P_BRAKE_FACTOR 0.1
// CORNERING_P_SPEED_FACTOR + CORNERING_D_SPEED_FACTOR must NEVER BE BIGGER THAN 1

/*=======
Function prototypes
========*/

/*======
~~lineCruise~~

Starts to cruise on a line at a specified speed.

MAKE SURE TO INITIALIZE THE LINE CRUISER FIRST!

inputs:
	(float) speed: The desired speed, in cm/s
outputs:
	(char) Return Status:	0 means ok
							1 means too fast
							2 means curvature too small
Globals affected:  Line sensor,	Timer A0, Timer A2, eventually Motor pins.
======*/
char lineCruise(float speed);

/*======
~~lineCruiserInit~~

Initializes the line cruiser.

MAKE SURE THE SCHEDULER IS INITIALIZED BEFORE CALLING THIS FUNCTION

inputs: none
outputs:
	(char) Return Status:	0 means ok
							1 means failed
Globals affected:  Line sensor,	Timer A0, Timer A2, eventually the motor pins, Scheduler call stack
======*/
char lineCruiserInit();


#endif