#include "PrintLine.h"

	PrintLine::PrintLine(const char *message, int line)
	{
		Requires(dslcd);
		xmessage = message;
		xline = line;
	}
	
	void PrintLine::Initialize()
	{
	}

    /**
     * Tells the Shooter to do nothing, stopping any previous movement.
     */
	void PrintLine::Execute()
	{
		dslcd->PrintfLine((DSLCD::Line)xline, xmessage);
	}

	bool PrintLine::IsFinished()
	{
		return true;
	}
	
	void PrintLine::End()
	{
		
	}
	
	void PrintLine::Interrupted()
	{
	}
