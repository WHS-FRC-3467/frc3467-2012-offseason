#include "DynamicArm.h"

DynamicArm::DynamicArm() {
	Requires(arm);
}
void DynamicArm::Initialize()
{
}


void DynamicArm::Execute()
{
	opY = oi->opLeftY(); 
	if (opY < 0){
		opY = 0;
	}
//	opY = 2.91 - (opY / 2.5);
	opY = Arm::STOW - (Arm::STOW - Arm::BOTTOM)*opY;

//	printf("Pos: %f\n", arm->ReturnPIDInput());

	arm->SetSetPoint(opY);
}



bool DynamicArm::IsFinished()
{
	return false;
}

void DynamicArm::End()
{
}

void DynamicArm::Interrupted()
{
}
