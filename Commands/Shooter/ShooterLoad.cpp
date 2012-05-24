#include "ShooterLoad.h"

    /**
     * Initialize the command so that it requires the BallCollector. This means it will
     * be interrupted if another command requiring the BallCollector is run.
     */
	ShooterLoad::ShooterLoad()
	{
		Requires(loader);
	}
	
	void ShooterLoad::Initialize()
	{
	}

    /**
     * Tells the BallCollector to collect balls.
     */
	void ShooterLoad::Execute()
	{
		loader->feed();
	}

    /**
     * @return false, so that it executes forever or until another command
     *         interrupts it.
     */
	bool ShooterLoad::IsFinished()
	{
		return false;
	}
	
	void ShooterLoad::End()
	{
	}
	
	void ShooterLoad::Interrupted()
	{
		loader->stopFeed();
	}
