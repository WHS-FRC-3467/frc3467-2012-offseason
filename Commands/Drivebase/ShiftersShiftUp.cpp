#include "ShiftersShiftUp.h"

	ShiftersShiftUp::ShiftersShiftUp()
	{
		Requires(shifters);
		SetTimeout(0.1);
	}
	
	void ShiftersShiftUp::Initialize()
	{
	}

	void ShiftersShiftUp::Execute()
	{
		shifters->shiftHigh();
	}

	bool ShiftersShiftUp::IsFinished()
	{
		return IsTimedOut();
	}
	
	void ShiftersShiftUp::End()
	{
		shifters->shiftOff();
	}
	
	void ShiftersShiftUp::Interrupted()
	{
		this->End();
	}
