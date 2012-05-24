#ifndef ARMCOLLECTOR_H
#define ARMCOLLECTOR_H
#include "Commands/Subsystem.h"
#include "Relay.h"



class ArmCollector: public Subsystem {
private:
	Relay *collectorMotor;
	
public:
	void InitDefaultCommand();
	ArmCollector();
	void collect();
	void eject();
	void noCollect();
	void doNothing();
};

#endif
