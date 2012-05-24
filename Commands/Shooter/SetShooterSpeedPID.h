#ifndef SET_SHOOTER_SPEED_PID_H
#define SET_SHOOTER_SPEED_PID_H

#include "../../CommandBase.h"
#include "../DriverStation/PrintLine.h"


class SetShooterSpeedPID: public CommandBase
{
private:
	double setpoint;
public:
	SetShooterSpeedPID(double s);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
