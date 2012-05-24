#include "queryShooter.h"

   
	queryShooter::queryShooter()
	{
		Requires(speedsensor);
	}
	
	void queryShooter::Initialize()
	{
	}

	void queryShooter::Execute()
	{
		speedsensor->Query();
	}

	bool queryShooter::IsFinished()
	{
		return true;
	}
	
	void queryShooter::End()
	{
	}
	
	void queryShooter::Interrupted()
	{
		
	}
