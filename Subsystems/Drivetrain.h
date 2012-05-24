#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "Commands/Subsystem.h"
#include "CANJaguar.h"
#include "RobotDrive.h"
#include "../Robotmap.h"


/**
 * <p>The drive train is PID subsystem, but unlike the {@link Wrist} and
 * {@link Elevator}, it is not always running PID. Instead, it can be run in a
 * manual tank drive or PID can be enabled and it will use a range finder to
 * drive a fixed distance away from the target.</p>
 * 
 * <p>Recommended next step: {@link CommandBase}</p>
 */
class Drivetrain : public Subsystem
{
private:
	static const double Kp = 3.0;
	static const double Ki = 0.2;
	static const double Kd = 0.0;
	
	CANJaguar	*jag1;
	CANJaguar	*jag2;
#ifndef PRACTICE_BOT
	CANJaguar	*jag3;
	CANJaguar	*jag4;
#endif
	
	RobotDrive	*drive;

public:
	Drivetrain();
	virtual void InitDefaultCommand();
	void tankDrive(float left, float right);
//	void status();
};

#endif
