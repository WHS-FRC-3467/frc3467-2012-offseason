#include "ShooterLoadTimed.h"

    /**
     * Initialize the command so that it requires the BallCollector. This means it will
     * be interrupted if another command requiring the BallCollector is run.
     */
	ShooterLoadTimed::ShooterLoadTimed(float timeout)
	{
		Requires(loader);
		SetTimeout(timeout);
	}
	
	void ShooterLoadTimed::Initialize()
	{
	}

    /**
     * Tells the BallCollector to collect balls.
     */
	void ShooterLoadTimed::Execute()
	{
		loader->feed();
	}

    /**
     * @return false, so that it executes forever or until another command
     *         interrupts it.
     */
	bool ShooterLoadTimed::IsFinished()
	{
		return IsTimedOut();
	}
	
	void ShooterLoadTimed::End()
	{
		this->Interrupted();
	}
	
	void ShooterLoadTimed::Interrupted()
	{
		loader->stopFeed();
	}
