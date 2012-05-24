#ifndef SHOOTER_LOADER_H
#define SHOOTER_LOADER_H
#include "Commands/Subsystem.h"
#include "CANJaguar.h"
#include "Relay.h"

class ShooterLoader: public Subsystem {
private:

	Relay	  *feedmotor;
	
	
public:
	ShooterLoader();
	void feed();
	void unload();
	void stopFeed();
	void InitDefaultCommand();
	void doNothing();
};

#endif
