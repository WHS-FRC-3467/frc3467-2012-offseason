#ifndef __DPAD_BUTTON_H__
#define __DPAD_BUTTON_H__

#include "GenericHID.h"
#include "Gamepad.h"
#include "Buttons/Button.h"

class DPadButton : public Button {
public:
	DPadButton(GenericHID *joystick, Gamepad::DPadDirection pad);
	~DPadButton();
	bool Get();

private:
	GenericHID *m_joystick;
	Gamepad::DPadDirection m_pad;
};

#endif
