#include "ManualArmControl.h"
#include "SetArmPos.h"

ManualArmControl::ManualArmControl()
{
	Requires(arm);
}

void ManualArmControl::Initialize()
{

}

void ManualArmControl::Execute()
{
#ifdef MANUAL_OVERRIDE_ARM
		arm->DirectDrive(oi->opLeftY());
		printf("Pos: %f\n", arm->ReturnPIDInput());
#endif
//		dslcd->PrintfLine(DSLCD::kArm, "Pos: %f\n", arm->ReturnPIDInput());
}

bool ManualArmControl::IsFinished()
{
	return false;
}

void ManualArmControl::End()
{
}

void ManualArmControl::Interrupted()
{
}
