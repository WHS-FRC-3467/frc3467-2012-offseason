#include "ArmCollect.h"

	ArmCollect::ArmCollect()
	{
		Requires(collector);

	}
	
	void ArmCollect::Initialize()
	{
	}


	void ArmCollect::Execute()
	{
		collector->collect();
	}


	bool ArmCollect::IsFinished()
	{
		return false;
	}
	
	void ArmCollect::End()
	{
	}
	
	void ArmCollect::Interrupted()
	{
		collector->noCollect();
	}
