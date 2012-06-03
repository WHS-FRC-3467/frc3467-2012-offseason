#ifndef ROBOTMAP_H
#define ROBOTMAP_H

//Practice Robot mode (no arm, no shifters, no pneumatics)
//#define PRACTICE_BOT				1

// Manual override for arm (No potentiometer in the arm).
//#define MANUAL_OVERRIDE_ARM		1

// Manual override for shooter (No counter in the shooter).
#define MANUAL_OVERRIDE_SHOOTER		1

// Autonomous shooter speed
#define AUTO_SHOOTER_SPEED			.73

// Shooter Speeds
#define SHOOTER_MIN_SPEED			.65   // X
#define SHOOTER_LOW_SPEED			.73	  // A
#define SHOOTER_HI_SPEED			.79   // B
#define SHOOTER_MAX_SPEED			1.0   // Y

//Device Definitions
// Analog Sensors.
#define ARM_POT						7

// Digital Sensors.
#define PRESSURE_SWITCH				1
#define SHOOTER_SPEED_SENSOR		10


// CAN Motors.
#define LEFT_FRONT_DRIVE_MOTOR		2
#define LEFT_REAR_DRIVE_MOTOR		3
#define RIGHT_FRONT_DRIVE_MOTOR		5
#define RIGHT_REAR_DRIVE_MOTOR		6

#define ARM_MOTOR					4

#define SHOOTER_MOTOR_1				7
#define SHOOTER_MOTOR_2				8

//Motor Safety Timeout.
#define MOTOR_SAFETY_TIME 			5

// Relays.
#define COMPRESSOR_RELAY			1
#define COLLECTOR_MOTOR				8
#define FEED_MOTOR					2

// Solenoids.
#define LEFT_SHIFT_SOLENOID			1
#define RIGHT_SHIFT_SOLENOID		2

#endif
