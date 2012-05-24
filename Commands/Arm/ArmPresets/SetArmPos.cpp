#include "SetArmPos.h"
#include "Math.h"

/**
 * Require the basket and store the desired setpoint.
 * 
 * @param setpoint The desired setpoint for the basket arm.
 */
SetArmPos::SetArmPos(double setpoint)
{
	Requires(arm);
	this->setpoint = setpoint;
}

/**
 * Set the wrist's setpoint to the desired setpoint
 */
void SetArmPos::Initialize()
{
	arm->SetSetPoint(setpoint);
}

/**
 * Do nothing, the PID loop is running in the background
 */
void SetArmPos::Execute()
{
}

/**
 * @return true if the wrist is close enough to in position.
 */
bool SetArmPos::IsFinished()
{
	return fabs(arm->GetPosition() - setpoint) < 0.05;
}

void SetArmPos::End()
{
}

void SetArmPos::Interrupted()
{
}
