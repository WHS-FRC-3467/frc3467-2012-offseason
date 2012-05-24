#include "Arm.h"
#include "../Robotmap.h"
#include "../Commands/Arm/ArmCollectorDoNothing.h"


ArmCollector::ArmCollector() : Subsystem("ArmCollector")
{
    // The Arm's collectorMotor, run by a Spike
    collectorMotor = new Relay(COLLECTOR_MOTOR);

}
    
/**
 * Initialize the default command to be {@link ArmDoNothing}.
 */
void ArmCollector::InitDefaultCommand()
{

}
void ArmCollector::collect()
{
	collectorMotor->Set(Relay::kForward);
}
void ArmCollector::eject()
{
	collectorMotor->Set(Relay::kReverse);
}
void ArmCollector::noCollect(){
	collectorMotor->Set(Relay::kOff);
}

void ArmCollector::doNothing()
{
}
