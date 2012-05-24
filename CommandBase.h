#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H
#include "Subsystems/SpeedSensor.h"
#include "Commands/Command.h"
#include "Subsystems/Drivetrain.h"
#include "Subsystems/Arm.h"
#include "Subsystems/ShooterLoader.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/Shifters.h"
#include "Subsystems/DSLCD.h"
//#include "Subsystems/Camera.h"
#include "Subsystems/ArmCollector.h"
#include "OI.h"
#include "Robotmap.h"


/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command
{

public:
	CommandBase(const char *name);
	CommandBase();
	static void init();

	// Create a single static instance of all of your subsystems
	static DSLCD			*dslcd;
	static Arm				*arm;
	static ArmCollector		*collector;
	static Shifters			*shifters;
	static Drivetrain		*drivetrain;
	static ShooterLoader	*loader;
	static Shooter			*shooter;
	static SpeedSensor		*speedsensor;
//	static Camera			*camera;
	static OI 				*oi;
	
};

#endif
