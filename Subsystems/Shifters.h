#ifndef SHIFTERS_H
#define SHIFTERS_H

#include "Commands/Subsystem.h"
#include "Solenoid.h"

class Shifters: public Subsystem
{
private:
	Solenoid *sole1;
	Solenoid *sole2;
	
public:
	Shifters();
	void InitDefaultCommand();
	void shiftHigh();
	void shiftLow();
	void shiftOff();
};

#endif
