#include "Drivetrain.h"
#include "../Robotmap.h"
#include "../Commands/Drivebase/DriveWithGamepad.h"

Drivetrain::Drivetrain() : Subsystem("Drivetrain")
{

#ifndef PRACTICE_BOT
	jag1 = new CANJaguar(LEFT_FRONT_DRIVE_MOTOR);
	jag2 = new CANJaguar(LEFT_REAR_DRIVE_MOTOR);
	jag3 = new CANJaguar(RIGHT_FRONT_DRIVE_MOTOR);
	jag4 = new CANJaguar(RIGHT_REAR_DRIVE_MOTOR);
	drive = new RobotDrive(jag1, jag2, jag3, jag4);
	jag1->SetSafetyEnabled(FALSE);
	jag2->SetSafetyEnabled(FALSE);
	jag3->SetSafetyEnabled(FALSE);
	jag4->SetSafetyEnabled(FALSE);
//	jag1->SetExpiration(MOTOR_SAFETY_TIME);
//	jag2->SetExpiration(MOTOR_SAFETY_TIME);
//	jag3->SetExpiration(MOTOR_SAFETY_TIME);
//	jag4->SetExpiration(MOTOR_SAFETY_TIME);
#else
	jag1 = new CANJaguar(3);
	jag2 = new CANJaguar(2);
	drive = new RobotDrive(jag1, jag2);
	drive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, TRUE);
	drive->SetInvertedMotor(RobotDrive::kFrontRightMotor, TRUE);
	drive->SetSafetyEnabled(false);
	jag1->SetExpiration(MOTOR_SAFETY_TIME);
	jag2->SetExpiration(MOTOR_SAFETY_TIME);
	
	
#endif

}

/**
 * Set the default command to drive with joysticks.
 */
void Drivetrain::InitDefaultCommand() {
	SetDefaultCommand(new DriveWithGamepad());
}

/**
 * Implements the tank drive capability of the drivetrain.
 * 
 * @param left The speed for the left side of the drivetrain.
 * @param right The speed for the right side of the drivetrain.
 */
void Drivetrain::tankDrive(float left, float right) {
	drive->TankDrive(left, right);
}
