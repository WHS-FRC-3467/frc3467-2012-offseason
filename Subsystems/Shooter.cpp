#include "Shooter.h"
#include "../Robotmap.h"
#include "../Commands/Shooter/SetShooterSpeedPID.h"
#include "WPILib.h"

Shooter::Shooter() : PIDSubsystem("Shooter", Kp, Ki, Kd)
{
	speedcounter = new Counter(10);
	speedcounter->Reset();
	speedcounter->Start();
	dio = new DigitalOutput(5);
#ifndef PRACTICE_BOT
	motor1 = new CANJaguar(SHOOTER_MOTOR_1);
    motor2 = new CANJaguar(SHOOTER_MOTOR_2);
#else
	motor1 = new CANJaguar(4);
    motor2 = new CANJaguar(5);    
#endif

    configJags();

	m_ds = DriverStation::GetInstance();
	currSpeed = 0.0;
    Enable();
    SetSetpoint(0);
}

void Shooter::configJags()
{
    motor1->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
    motor2->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
	motor1->SetSafetyEnabled(FALSE);
	motor2->SetSafetyEnabled(FALSE);
	
	motor1->ConfigFaultTime(0.5);
	motor2->ConfigFaultTime(0.5);
	
//    motor1->SetExpiration(MOTOR_SAFETY_TIME);
//    motor2->SetExpiration(MOTOR_SAFETY_TIME);
}

void Shooter::InitDefaultCommand()
{
}

double Shooter::ReturnPIDInput() {
	double speed = 60/(speedcounter->GetPeriod()*8);
	if(speed > 2600)
		speed = 2600;
	if(speed < 0){
		speed = 0;
	}
	return speed;
}

void Shooter::SetSetPoint(float setpoint){
	SetSetpoint(setpoint);
}

void Shooter::UsePIDOutput(double output)
{
#ifdef MANUAL_OVERRIDE_SHOOTER
	currSpeed = GetSetpoint();
	updateMotorSpeeds();
#else
	currSpeed = output;
	updateMotorSpeeds();
#endif

}

void Shooter::killShooter() {
	SetSetpoint(0);
}

void Shooter::updateMotorSpeeds()
{
	UINT8 syncGroup = 0x10;

	// Check the  current battery voltage; we will use it to adjust the shooter speed
	float voltage = m_ds->GetBatteryVoltage();

	// If either Jag has been power cycled since last time we came through, reinintialize them both
	if (motor1->GetPowerCycled() || motor2->GetPowerCycled())
		configJags();
	
	// Here is where we normalize the commanded speed, based on the current battery voltage
	currSpeed = (currSpeed * 11.5)/voltage;
//	printf("V: %f    S: %f\n", voltage, currSpeed);
	
	// Don't let commanded speed go to 1.0, and don't let it go negative
	if (currSpeed > 0.99)
		currSpeed = 0.99;
	else if (currSpeed < 0.0)
		currSpeed = 0.0;
	
	// Set up the desired motor speeds, but don't send the commands to the motors yet...
	motor1->Set(currSpeed, syncGroup);
	motor2->Set(currSpeed, syncGroup);

	// Now tell the motors the new speed AT THE SAME TIME.
	// (This should prevent any overloading of the Jags that might
	// happen if they didn't come up to speed at the same time)
	CANJaguar::UpdateSyncGroup(syncGroup);

}
