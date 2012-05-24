#include "ShiftersShiftDown.h"

	ShiftersShiftDown::ShiftersShiftDown()
	{
		Requires(shifters);
		SetTimeout(0.1);
	}
	
	void ShiftersShiftDown::Initialize()
	{
	}

	void ShiftersShiftDown::Execute()
	{
		shifters->shiftLow();
	}

	bool ShiftersShiftDown::IsFinished()
	{
		return IsTimedOut();
	}
	
	void ShiftersShiftDown::End()
	{
		shifters->shiftOff();
	}
	
	void ShiftersShiftDown::Interrupted()
	{
		this->End();
	}
