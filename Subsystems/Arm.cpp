#include "Arm.h"
#include "../Robotmap.h"
#include "../Commands/Arm/ArmPresets/ManualArmControl.h"
#include "../Commands/Arm/ArmPresets/DynamicArm.h"

Arm::Arm() : PIDSubsystem("Arm", Kp, Ki, Kd)
{
    armMotor = new CANJaguar(ARM_MOTOR);
    configJag();

    pot = new AnalogChannel(ARM_POT);
    SetSetpoint(STOW);

#ifndef MANUAL_OVERRIDE_ARM
    Enable();
	printf("Arm set to PID control...\n");
#else
    armMotor->SetSafetyEnabled(FALSE);
	printf("Arm set to manual...\n");
#endif
}
 
void Arm::configJag()
{
    armMotor->ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
    armMotor->SetExpiration(MOTOR_SAFETY_TIME);
	armMotor->ConfigFaultTime(0.5);
}



void Arm::InitDefaultCommand()
{
#ifdef MANUAL_OVERRIDE_ARM
	SetDefaultCommand(new ManualArmControl());
#else
	SetDefaultCommand(new DynamicArm());
#endif
	
}

double Arm::ReturnPIDInput() {
	double voltage = pot->GetVoltage();
	return voltage;
}

void Arm::SetSetPoint(float setpoint){
	SetSetpoint(setpoint);
}
void Arm::UsePIDOutput(double output) {

	if (armMotor->GetPowerCycled())
		configJag();
	
	if (output > .95)
		output = 0.95;
	if (output < -.95)
		output = -0.95;

//	armMotor->Set(-output);
	armMotor->Set(output);
}

void Arm::DirectDrive(float input){
	armMotor->Set(input);
}

void Arm::doNothing()
{
}
