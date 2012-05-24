#include "DriveWithGamepad.h"

DriveWithGamepad::DriveWithGamepad()
{
	Requires(drivetrain);
}

void DriveWithGamepad::Initialize()
{
}

/**
 * Have the drivetrain drive tank drive with the latest values from Gamepad.
 */
void DriveWithGamepad::Execute()
{
	drivetrain->tankDrive(oi->drvLeftY(), oi->drvRightY());
}

/**
 * @return false, so that it executes forever or until another command
 *         interrupts it.
 */
bool DriveWithGamepad::IsFinished()
{
	return false;
}

void DriveWithGamepad::End()
{
}

void DriveWithGamepad::Interrupted()
{
}
