#include "CommandBase.h"
#include "Commands/Scheduler.h"
#include "SmartDashboard/SmartDashboard.h"


CommandBase::CommandBase(const char *name) : Command(name)
{
}

CommandBase::CommandBase() : Command()
{
}
DSLCD			*CommandBase::dslcd = NULL;
SpeedSensor		*CommandBase::speedsensor = NULL;
ArmCollector	*CommandBase::collector = NULL;
Arm				*CommandBase::arm = NULL;
Shifters		*CommandBase::shifters = NULL;
Drivetrain		*CommandBase::drivetrain = NULL;
Shooter			*CommandBase::shooter = NULL;
//Camera			*CommandBase::camera = NULL;
ShooterLoader	*CommandBase::loader = NULL;
OI				*CommandBase::oi = NULL;

void CommandBase::init(){
	dslcd = new DSLCD();
	printf("Driver Station LCD link established...\n");
#ifndef PRACTICE_BOT

	arm = new Arm();
	printf("Arm Initialized...\n");
	collector = new ArmCollector();
	printf("Arm Collector Initialized...\n");
	shifters = new Shifters();
	printf("Super Shifters Initialized...\n");
	
	
#endif
	drivetrain = new Drivetrain();
	printf("Drivebase Initialized...\n");
	shooter = new Shooter();
	printf("Shooter Initialized...\n");
	loader = new ShooterLoader();
	printf("Shooter Loader Initialized...\n");
//	camera = new Camera();
//	printf("Camera Initialized...\n");
	speedsensor = new SpeedSensor();
	printf("Shooter Speed Sensor Initialized...\n");
	oi = new OI();
	printf("OI Initialized...\n");
	
	
}

