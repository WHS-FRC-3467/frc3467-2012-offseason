
#include "Gamepad.h"
#include "DriverStation.h"
#include "Utility.h"

/**
 * Construct an instance of a Gamepad.
 *
 * @param port The port on the driver station that the gamepad is plugged into.
 */
Gamepad::Gamepad(UINT32 port)
{
    m_port = port;
    m_ds = DriverStation::GetInstance();
}

Gamepad::~Gamepad()
{
}

/**
 * Get the X value of either the left or right analog stick.
 */
float Gamepad::GetX(JoystickHand hand)
{
	if (hand == kRightHand)
		return GetRawAxis(kRightXAxisNum);
	else
		return GetRawAxis(kLeftXAxisNum);		
}

/**
 * Get the X value of the left analog stick.
 */
float Gamepad::GetLeftX()
{
    return GetRawAxis(kLeftXAxisNum);
}

/**
 * Get the X value of the right analog stick.
 */
float Gamepad::GetRightX()
{
    return GetRawAxis(kRightXAxisNum);
}

/**
 * Get the Y value of either the left or right analog stick.
 */
float Gamepad::GetY(JoystickHand hand)
{
	if (hand == kRightHand)
		return GetRawAxis(kRightYAxisNum);
	else
		return GetRawAxis(kLeftYAxisNum);		
}

/**
 * Get the Y value of the left analog stick.
 */
float Gamepad::GetLeftY()
{
    return GetRawAxis(kLeftYAxisNum);
}

/**
 * Get the Y value of the right analog stick.
 */
float Gamepad::GetRightY()
{
    return GetRawAxis(kRightYAxisNum);
}

/**
 * Return the value of the axis determined by the argument.
 *
 * This is for cases where the gamepad axis is returned programatically,
 * otherwise one of the previous functions would be preferable (for example
 * GetLeftX()).
 *
 * @param axis The axis to read.
 * @return The value of the axis.
 */
float Gamepad::GetAxis(AxisType axis)
{
    switch(axis)
    {
        case kLeftXAxis: return GetLeftX();
        case kLeftYAxis: return GetLeftY();
        case kRightXAxis: return GetRightX();
        case kRightYAxis: return GetRightY();
        default:
            return 0.0;
    }
}

/**
 * Get the value of the axis.
 *
 * @param axis The axis to read [1-6].
 * @return The value of the axis.
 */
float Gamepad::GetRawAxis(UINT32 axis)
{
    return m_ds->GetStickAxis(m_port, axis);
}

// These methods are required for implementing the GenericHID interface;
// They don't do anything on a Gamepad
float Gamepad::GetZ()
{
	return 0.0;
}
float Gamepad::GetTwist()
{
	return 0.0;
}
float Gamepad::GetThrottle()
{
	return 0.0;
}
bool Gamepad::GetTop(JoystickHand hand)
{
	return false;
}

/**
 * Get the button value for buttons 1 through 12.
 *
 * The buttons are returned in a single 16 bit value with one bit representing
 * the state of each button. The appropriate button is returned as a boolean
 * value.
 *
 * @param button The button number to be read.
 * @return The state of the button.
 **/
bool Gamepad::GetRawButton(UINT32 button)
{
    return ((0x1 << (button-1)) & m_ds->GetStickButtons(m_port)) != 0;
}

bool Gamepad::GetNumberedButton(UINT32 button)
{
	return GetRawButton(button);
}

bool Gamepad::GetTrigger(JoystickHand hand)
{
	if (hand == kRightHand)
		return GetRawButton(kRightTriggerButton);
	else
		return GetRawButton(kLeftTriggerButton);			
}

bool Gamepad::GetBumper(JoystickHand hand)
{
	if (hand == kRightHand)
		return GetRawButton(kRightBumperButton);
	else
		return GetRawButton(kLeftBumperButton);		
}

/**
 * Gets whether or not the left analog stick is depressed.
 *
 * @return The state of the left analog stick button.
 */
bool Gamepad::GetLeftPush()
{
    return GetRawButton(kLeftAnalogStickButton);
}

/**
 * Gets whether or not the right analog stick is depressed.
 *
 * @return The state of the right analog stick button.
 */
bool Gamepad::GetRightPush()
{
    return GetRawButton(kRightAnalogStickButton);
}

Gamepad::DPadDirection Gamepad::GetDPad()
{
    float x = GetRawAxis(kDPadXAxisNum);
    float y = GetRawAxis(kDPadYAxisNum);

    if (x < -0.5 && y < -0.5)
        return kUpLeft;
    if (x < -0.5 && y > 0.5)
        return kDownLeft;
    if (x > 0.5 && y > 0.5)
        return kDownRight;
    if (x > 0.5 && y < -0.5)
        return kUpRight;
    if (y < -0.5)
        return kUp;
    if (x < -0.5)
        return kLeft;
    if (y > 0.5)
        return kDown;
    if (x > 0.5)
        return kRight;

  return kCenter;
}

