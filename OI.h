#ifndef OI_H
#define OI_H

#include "Peripherals/Gamepad.h"
#include "Peripherals/DPadButton.h"
#include "Buttons/Button.h"

class OI
{
private:
	Gamepad *drivepad;
	Gamepad *oppad;

	Button *drive_button1;
	Button *drive_button2;
	Button *drive_button3;
	Button *drive_button4;
	Button *drive_button5;
	Button *drive_button6;
	Button *drive_button7;
	Button *drive_button8;
	Button *drive_button9;
	Button *drive_button10;
	Button *drive_button11;
	Button *drive_button12;

	Button *op_button1;
	Button *op_button2;
	Button *op_button3;
	Button *op_button4;
	Button *op_button5;
	Button *op_button6;
	Button *op_button7;
	Button *op_button8;
	Button *op_button9;
	Button *op_button10;
	Button *op_button11;
	Button *op_button12;
	Button *op_dpadup;
	Button *op_dpaddown;
	
public:
	OI();
	double drvLeftY();
	double drvRightY();
	double opLeftY();
};

#endif
