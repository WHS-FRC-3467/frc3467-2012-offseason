#ifndef SHOOTER_H
#define SHOOTER_H
#include "Commands/PIDSubsystem.h"
#include "CANJaguar.h"
#include "Relay.h"
#include "Counter.h"
#include "DigitalOutput.h"
#include "DriverStation.h"
#include "PIDController.h"

class Shooter: public PIDSubsystem {
private:
	static const double Kp = 1;
	static const double Ki = 0;
	static const double Kd = 0;
	Counter		*speedcounter;
	DigitalOutput *dio;
	CANJaguar *motor1;
	CANJaguar *motor2;
	Relay	  *feedmotor;
	DriverStation *m_ds;
	void updateMotorSpeeds();
	void configJags();
	
public:
	float	  currSpeed;
	
	virtual double ReturnPIDInput();
	void SetSetPoint(float setpoint);
	virtual void UsePIDOutput(double output);
	Shooter();
	void feed();
	void unload();
	void stopFeed();
	void InitDefaultCommand();
	void killShooter();
	
};

#endif
