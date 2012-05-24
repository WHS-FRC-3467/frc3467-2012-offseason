#include "AutoMain.h"
#include "../Shooter/SetShooterSpeedPID.h"
#include "../Shooter/ShooterLoadTimed.h"
#include "../Commands/WaitCommand.h"
#include "../DriverStation/PrintLine.h"

	AutoMain::AutoMain()
	{
		AddParallel(new SetShooterSpeedPID(AUTO_SHOOTER_SPEED));
		AddParallel(new PrintLine("Waiting...\n", 0));
		AddSequential(new WaitCommand(5.0));
		
		AddParallel(new PrintLine("Firing...\n", 0));
		AddSequential(new ShooterLoadTimed(1.25));
		
		AddParallel(new PrintLine("Waiting...\n", 0));
		AddParallel(new SetShooterSpeedPID(AUTO_SHOOTER_SPEED));
		AddSequential(new WaitCommand(3.0));
		
		AddParallel(new PrintLine("Firing...\n", 0));
		AddSequential(new ShooterLoadTimed(4));
		
		AddParallel(new PrintLine("Done\n", 0));
		AddSequential(new SetShooterSpeedPID(0));
		
	}
	
	
