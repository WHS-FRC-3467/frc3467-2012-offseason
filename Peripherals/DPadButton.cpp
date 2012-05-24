/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2011. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "GamePad.h"
#include "DPadButton.h"

DPadButton::DPadButton(GenericHID *joystick, Gamepad::DPadDirection pad) :
	m_joystick(joystick),
	m_pad(pad)
{
}

DPadButton::~DPadButton(){
}

bool DPadButton::Get()
{
    float x = m_joystick->GetRawAxis(Gamepad::kDPadXAxisNum);
    float y = m_joystick->GetRawAxis(Gamepad::kDPadYAxisNum);

    switch (m_pad)
    {
    case Gamepad::kUpLeft:
    	if (x < -0.5 && y < -0.5)
    		return(true);
    	break;
    	
    case Gamepad::kUpRight:
    	if (x > 0.5 && y < -0.5)
    		return(true);
    	break;
    	
    case Gamepad::kDownLeft:
		if (x < -0.5 && y > 0.5)
			return true;
		break;
	
    case Gamepad::kDownRight:
		if (x > 0.5 && y > 0.5)
			return true;
		break;
	
    case Gamepad::kUp:
		if (y < -0.5)
			return true;
		break;
	
    case Gamepad::kLeft:
		if (x < -0.5)
			return true;
		break;
	
    case Gamepad::kDown:
		if (y > 0.5)
			return true;
		break;
	
    case Gamepad::kRight:
		if (x > 0.5)
			return true;
		break;
	
    case Gamepad::kCenter:
    	if (x > -.5 && x < .5 && y > -.5 && y < .5)
    		return true;
    	break;
    }
    return false;
}
