#include "ShooterUnload.h"

    /**
     * Initialize the command so that it requires the Shooter Feed. This means it will
     * be interrupted if another command requiring the Shooter Feed is run.
     */
	ShooterUnload::ShooterUnload()
	{
		Requires(loader);
	}
	
	void ShooterUnload::Initialize()
	{
	}

    /**
     * Tells the Shooter Feed to unload balls.
     */
	void ShooterUnload::Execute()
	{
		loader->unload();
	}

	bool ShooterUnload::IsFinished()
	{
		return false;
	}
	
	void ShooterUnload::End()
	{
	}
	
	void ShooterUnload::Interrupted()
	{
		loader->stopFeed();
	}
