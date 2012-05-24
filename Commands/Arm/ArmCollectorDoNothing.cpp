#include "ArmCollectorDoNothing.h"


	ArmCollectorDoNothing::ArmCollectorDoNothing()
	{
		Requires(collector);
	}
	
	void ArmCollectorDoNothing::Initialize()
	{
	}

 
	void ArmCollectorDoNothing::Execute()
	{
		collector->noCollect();
	}

	bool ArmCollectorDoNothing::IsFinished()
	{
		return false;
	}
	
	void ArmCollectorDoNothing::End()
	{
		
	}
	
	void ArmCollectorDoNothing::Interrupted()
	{
	}
