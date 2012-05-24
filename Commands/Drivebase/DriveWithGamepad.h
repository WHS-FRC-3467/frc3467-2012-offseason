#ifndef DRIVE_WITH_GAMEPAD
#define DRIVE_WITH_GAMEPAD

#include "../../CommandBase.h"

/**
 * <p>The default command for the drive train. When no other command is running,
 * the robot can be driven using the gamepad.</p>
 * 
 */
class DriveWithGamepad: public CommandBase {
public:
	DriveWithGamepad();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
