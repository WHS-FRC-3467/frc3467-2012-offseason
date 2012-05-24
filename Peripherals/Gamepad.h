
#ifndef GAMEPAD_H_
#define GAMEPAD_H_

//#include <stdio.h>
#include "GenericHID.h"
#include "ErrorBase.h"

class DriverStation;

/**
 * Handle input from Logitech Dual Action Gamepad connected to the Driver
 * Station.
 */
class Gamepad : public GenericHID, public ErrorBase
{
public:
    typedef enum
    {
        kLeftXAxis, kLeftYAxis, kRightXAxis, kRightYAxis
    } AxisType;

    typedef enum
    {
        kCenter, kUp, kUpLeft, kLeft, kDownLeft, kDown, kDownRight, kRight,
        kUpRight
    } DPadDirection;

    Gamepad(UINT32 port);
    ~Gamepad();

	virtual float GetX(JoystickHand hand = kRightHand);
    float GetLeftX();
    float GetRightX();
	virtual float GetY(JoystickHand hand = kRightHand);
    float GetLeftY();
    float GetRightY();
    float GetAxis(AxisType axis);
	virtual float GetRawAxis(UINT32 axis);

	// These methods are required for implementing the GenericHID interface;
	// They don't do anything on a Gamepad
	virtual float GetZ();
	virtual float GetTwist();
	virtual float GetThrottle();
	virtual bool GetTop(JoystickHand hand = kRightHand);
	
	// Button-handling
	virtual bool GetTrigger(JoystickHand hand = kRightHand);
	virtual bool GetBumper(JoystickHand hand = kRightHand);
	virtual bool GetRawButton(UINT32 button);
    
    bool GetNumberedButton(UINT32 button);
    bool GetLeftPush();
    bool GetRightPush();

    DPadDirection GetDPad();


    static const UINT32 kLeftXAxisNum = 1;
    static const UINT32 kLeftYAxisNum = 2;
    static const UINT32 kRightXAxisNum = 3;
    static const UINT32 kRightYAxisNum = 4;
    static const UINT32 kDPadXAxisNum = 5;
    static const UINT32 kDPadYAxisNum = 6;

protected:
	// TODO: Check Gamepad button numbers
    static const UINT32 kLeftTriggerButton = 5;
	static const UINT32 kLeftBumperButton = 6;
	static const UINT32 kRightTriggerButton = 7;
	static const UINT32 kRightBumperButton = 8;

    static const unsigned kLeftAnalogStickButton = 11;
    static const unsigned kRightAnalogStickButton = 12;

    DriverStation *m_ds;
    UINT32 m_port;
};

#endif // GAMEPAD_H_

