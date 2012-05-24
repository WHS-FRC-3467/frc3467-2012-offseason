#include "ArmEject.h"

	ArmEject::ArmEject()
	{
		Requires(collector);
	}
	
	void ArmEject::Initialize()
	{
	}

	void ArmEject::Execute()
	{
		collector->eject();
	}

	bool ArmEject::IsFinished()
	{
		return false;
	}
	
	void ArmEject::End()
	{
		
	}
	
	void ArmEject::Interrupted()
	{
		collector->noCollect();
	}
