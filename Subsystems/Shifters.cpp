#include "Shifters.h"
#include "../Robotmap.h"

Shifters::Shifters() : Subsystem("Shifters")
{
	sole1 = new Solenoid(LEFT_SHIFT_SOLENOID);
	sole2 = new Solenoid(RIGHT_SHIFT_SOLENOID);	
}
    
void Shifters::InitDefaultCommand()
{
}

void Shifters::shiftHigh()
{
	sole1->Set(true);
}

void Shifters::shiftLow()
{
	sole2->Set(true);
}

void Shifters::shiftOff()
{
	sole1->Set(false);
	sole2->Set(false);
}
    
