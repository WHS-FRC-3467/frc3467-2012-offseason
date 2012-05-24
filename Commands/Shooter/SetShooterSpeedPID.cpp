#include "SetShooterSpeedPID.h"
#include "Math.h"

/**
 * Require the basket and store the desired setpoint.
 * 
 * @param setpoint The desired setpoint for the basket arm.
 */
SetShooterSpeedPID::SetShooterSpeedPID(double setpoint)
{
	Requires(shooter);
	this->setpoint = setpoint;
}

/**
 * Set the wrist's setpoint to the desired setpoint
 */
void SetShooterSpeedPID::Initialize()
{
	
	double point = setpoint;
	shooter->SetSetPoint(point);
	dslcd->PrintfLine(dslcd->kShooter, "Speed = %f\n", point);
}

/**
 * Do nothing, the PID loop is running in the background
 */
void SetShooterSpeedPID::Execute()
{
}

/**
 * @return true if the wrist is close enough to in position.
 */
bool SetShooterSpeedPID::IsFinished()
{
//	return fabs(shooter->GetPosition() - setpoint) < 0.05;
	return true;
}

void SetShooterSpeedPID::End()
{
}

void SetShooterSpeedPID::Interrupted()
{
}
