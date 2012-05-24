#include "KillShooter.h"

    /**
     * Initialize the command so that it requires the ShooterFeed. This means it will
     * be interrupted if another command requiring the ShooterFeed is run.
     */
	KillShooter::KillShooter()
	{
		Requires(shooter);
	}
	
	void KillShooter::Initialize()
	{
	}

    /**
     * Tells the Shooter to do nothing, stopping any previous movement.
     */
	void KillShooter::Execute()
	{
		shooter->killShooter();
	}

    /**
     * @return false, so that it executes forever or until another command
     *         interrupts it.
     */
	bool KillShooter::IsFinished()
	{
		return false;
	}
	
	void KillShooter::End()
	{
		
	}
	
	void KillShooter::Interrupted()
	{
	}
