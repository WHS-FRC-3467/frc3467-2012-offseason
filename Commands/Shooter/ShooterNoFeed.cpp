#include "ShooterNoFeed.h"

    /**
     * Initialize the command so that it requires the ShooterFeed. This means it will
     * be interrupted if another command requiring the ShooterFeed is run.
     */
	ShooterNoFeed::ShooterNoFeed()
	{
		Requires(loader);
	}
	
	void ShooterNoFeed::Initialize()
	{
	}

    /**
     * Tells the ShooterFeed to do nothing, stopping any previous movement.
     */
	void ShooterNoFeed::Execute()
	{
		loader->stopFeed();
	}

    /**
     * @return false, so that it executes forever or until another command
     *         interrupts it.
     */
	bool ShooterNoFeed::IsFinished()
	{
		return false;
	}
	
	void ShooterNoFeed::End()
	{
		
	}
	
	void ShooterNoFeed::Interrupted()
	{
	}
