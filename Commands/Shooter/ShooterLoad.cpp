#include "ShooterLoad.h"

    /**
     * Initialize the command so that it requires the ShooterLoader. This means it will
     * be interrupted if another command requiring the ShooterLoader is run.
     */
	ShooterLoad::ShooterLoad()
	{
		Requires(loader);
	}
	
	void ShooterLoad::Initialize()
	{
	}

    /**
     * Tells the ShooterLoader to (continue to) run, feeding available balls to the shooter.
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
