#include "SpeedSensor.h"
#include "../Robotmap.h"
#include "../Commands/SpeedSensor/queryShooter.h"

SpeedSensor::SpeedSensor() : Subsystem("SpeedSensor")
{
	speedSensor = new Counter(SHOOTER_SPEED_SENSOR);
	speedSensor->Start();
	speedSensor->Reset();
}
    
void SpeedSensor::InitDefaultCommand()
{
}

double SpeedSensor::Query(){
	double period = speedSensor->GetPeriod();
	printf("Speed Period is %f\n", period);
	return period;
	
}
