#ifndef SET_BASKETARM_SETPOINT_H
#define SET_BASKETARM_SETPOINT_H

#include "../../../CommandBase.h"


class SetArmPos: public CommandBase
{
private:
	double setpoint;
public:
	SetArmPos(double s);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
