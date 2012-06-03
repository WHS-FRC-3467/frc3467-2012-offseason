#include "OI.h"

#include "Commands/Arm/ArmCollect.h"
#include "Commands/Arm/ArmEject.h"
#include "Commands/Arm/ArmPresets/DropArm.h"
#include "Commands/Arm/ArmPresets/StowArm.h"
#include "Commands/Arm/QueryArmPot.h"

#include "Commands/Drivebase/ShiftersShiftUp.h"
#include "Commands/Drivebase/ShiftersShiftDown.h"

#include "Commands/Shooter/KillShooter.h"
#include "Commands/Shooter/ShooterLoad.h"
#include "Commands/Shooter/ShooterUnload.h"
#include "Commands/Shooter/SetShooterSpeedPID.h"

#include "Commands/DriverStation/PrintLine.h"
//#include "Commands/Camera/CameraAlign.h"


#include "Buttons/JoystickButton.h"

OI::OI()
{
	// Process operator interface input here.

	drivepad = new Gamepad(1);
	drive_button1 = new JoystickButton(drivepad, 1);
	drive_button2 = new JoystickButton(drivepad, 2);
	drive_button3 = new JoystickButton(drivepad, 3);
	drive_button4 = new JoystickButton(drivepad, 4);
	drive_button5 = new JoystickButton(drivepad, 5);
	drive_button6 = new JoystickButton(drivepad, 6);
	drive_button7 = new JoystickButton(drivepad, 7);
	drive_button8 = new JoystickButton(drivepad, 8);
	drive_button9 = new JoystickButton(drivepad, 9);
	drive_button10 = new JoystickButton(drivepad, 10);
	drive_button11 = new JoystickButton(drivepad, 11);
	drive_button12 = new JoystickButton(drivepad, 12);

	oppad = new Gamepad(2);
	op_button1 = new JoystickButton(oppad, 1);  // X
	op_button2 = new JoystickButton(oppad, 2);  // A
	op_button3 = new JoystickButton(oppad, 3);  // B
	op_button4 = new JoystickButton(oppad, 4);  // Y
	op_button5 = new JoystickButton(oppad, 5);
	op_button6 = new JoystickButton(oppad, 6);
	op_button7 = new JoystickButton(oppad, 7);
	op_button8 = new JoystickButton(oppad, 8);
	op_button9 = new JoystickButton(oppad, 9);
	op_button10 = new JoystickButton(oppad, 10);
	op_button11 = new JoystickButton(oppad, 11);
	op_button12 = new JoystickButton(oppad, 12);
	op_dpadup = new DPadButton(oppad, Gamepad::kUp);
	op_dpaddown = new DPadButton(oppad, Gamepad::kDown);

    /**
     * Bind the press of each button to a specific command or command group.
     */

	//drive_button1->WhenPressed(new Command());
	//drive_button2->WhenPressed(new Command());
	//drive_button3->WhenPressed(new Command());
	//drive_button4->WhenPressed(new Command());
	// For Jake
	drive_button5->WhenPressed(new ShiftersShiftUp());
	drive_button6->WhenPressed(new ShiftersShiftDown());
	//drive_button7->WhenPressed(new Command());
	//drive_button8->WhenPressed(new Command());
	//drive_button9->WhenPressed(new Command());
	//drive_button10->WhenPressed(new Command());
	drive_button11->WhenPressed(new ShiftersShiftUp());
	drive_button12->WhenPressed(new ShiftersShiftDown());

	op_button1->WhenPressed(new SetShooterSpeedPID(SHOOTER_MIN_SPEED));  // X
	op_button2->WhenPressed(new SetShooterSpeedPID(SHOOTER_LOW_SPEED));  // A
	op_button3->WhenPressed(new SetShooterSpeedPID(SHOOTER_HI_SPEED));   // B
	op_button4->WhenPressed(new SetShooterSpeedPID(SHOOTER_MAX_SPEED));  // Y
	op_button5->WhileHeld(new ArmCollect());
	op_button6->WhileHeld(new ShooterUnload());
	op_button7->WhileHeld(new ArmEject());
	op_button8->WhileHeld(new ShooterLoad());
	//	op_button9->WhenPressed(new queryShooter());
	op_button10->WhenPressed(new SetShooterSpeedPID(0));
	op_button11->WhileHeld(new DropArm());
	op_button12->WhenPressed(new StowArm());
//	op_dpadup->WhenPressed(new );
//	op_dpaddown->WhenPressed(new );
}

double OI::drvLeftY() {
	return (1 * drivepad->GetLeftY());
}

double OI::drvRightY() {
	return (1 * drivepad->GetRightY());
}

double OI::opLeftY() {
	return (-1 * oppad->GetLeftY());
}
