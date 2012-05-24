#ifndef SPEED_SENSOR_H
#define SPEED_SENSOR_H

#include "Commands/Subsystem.h"
#include "Encoder.h"



class SpeedSensor: public Subsystem {
private:
	Counter *speedSensor;
	
public:
	SpeedSensor();
	double Query();
private:
	void InitDefaultCommand();

};

#endif
