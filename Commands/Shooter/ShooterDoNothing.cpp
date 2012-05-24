#include "ShooterDoNothing.h"

    /**
     * Initialize the command so that it requires the ShooterFeed. This means it will
     * be interrupted if another command requiring the ShooterFeed is run.
     */
	ShooterDoNothing::ShooterDoNothing()
	{
		Requires(shooter);
	}
	
	void ShooterDoNothing::Initialize()
	{
	}

    /**
     * Tells the Shooter to do nothing, stopping any previous movement.
     */
	void ShooterDoNothing::Execute()
	{
		shooter->doNothing();
	}

    /**
     * @return false, so that it executes forever or until another command
     *         interrupts it.
     */
	bool ShooterDoNothing::IsFinished()
	{
		return false;
	}
	
	void ShooterDoNothing::End()
	{
		
	}
	
	void ShooterDoNothing::Interrupted()
	{
	}
