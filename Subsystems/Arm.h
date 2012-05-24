#ifndef ARM_H
#define ARM_H
#include "Commands/Subsystem.h"
#include "Commands/PIDSubsystem.h"
#include "Relay.h"
#include "CANJaguar.h"
#include "AnalogChannel.h"



class Arm: public PIDSubsystem {
private:
//	static const double Kp = 10;
	static const double Kp = 10;
	static const double Ki = 0;
	static const double Kd = 0;
	CANJaguar *armMotor;
	AnalogChannel *pot;
	
	void configJag();
	
public:
    Arm();
    void SetSetPoint(float setpoint);
    static const double BOTTOM = 2.12;
    static const double STOW = 2.49;
    virtual void UsePIDOutput(double output);
    void DirectDrive(float input);
    virtual double ReturnPIDInput();
	void InitDefaultCommand();
	void doNothing();
};

#endif
