#include "ShooterLoadTimed.h"

    /**
     * Initialize the command so that it requires the ShooterLoader. This means it will
     * be interrupted if another command requiring the ShooterLoader is run.
     * 
     * The timeout parameter tells the ShooterLoader how long to run.
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
     * Tells the ShooterLoader to (continue to) run, feeding available balls to the shooter.
     */
	void ShooterLoadTimed::Execute()
	{
		loader->feed();
	}

    /**
     * Run until this command instance times out
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
