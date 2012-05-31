#include "Shooter.h"
#include "../Robotmap.h"
#include "../Commands/Shooter/ShooterNoFeed.h"

ShooterLoader::ShooterLoader() : Subsystem("ShooterLoader")
{
	feedmotor = new Relay(FEED_MOTOR);
}
    
/**
 * Initialize the default command to be {@link ShooterNoFeed}.
 */
void ShooterLoader::InitDefaultCommand()
{
	SetDefaultCommand(new ShooterNoFeed());
}
void ShooterLoader::feed()
{
	feedmotor->Set(Relay::kForward);
}
void ShooterLoader::unload() {
	feedmotor->Set(Relay::kReverse);
}
void ShooterLoader::stopFeed() {
	feedmotor->Set(Relay::kOff);
}


void ShooterLoader::doNothing() {

}
