#include "IterativeRobot.h"
#include "Compressor.h"
#include "CommandBase.h"
#include "Commands/Command.h"
#include "Commands/Scheduler.h"
#include "Commands/AutonomousCommands/AutoMain.h"
#include "DriverStation.h"
#include "taskLibCommon.h"
#include "Utility.h"

class Robot3467_2012 : public IterativeRobot
{
private:
	Command 		*autonomousCommand;
	Compressor		*comp;
	DriverStation 	*ds;
	virtual void RobotInit()
	{
		CommandBase::init();
		printf("CommandBase initialized successfully\nInit Complete\n");
		comp = new Compressor(PRESSURE_SWITCH, COMPRESSOR_RELAY);
		ds = DriverStation::GetInstance();
		comp->Start();
		autonomousCommand = new AutoMain();
		
		wpi_stackTraceOnAssertEnable(true);
	}
	
	~Robot3467_2012()
	{
		delete comp;
		delete autonomousCommand;
	}
	
	virtual void AutonomousInit()
	{
		printf("Autonomous Enabled!\n");
		autonomousCommand->Start();
	}
	
	virtual void DisabledContinuous(){
		ds->WaitForData();
	}
	
	virtual void DisabledPeriodic(){
		taskDelay(1);
	}
	
	virtual void DisabledInit(){
	}
	
	virtual void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}
	
	virtual void TeleopInit()
	{
		printf("Teleop Enabled!\n");
		autonomousCommand->Cancel();
	}
	
	virtual void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}
};

START_ROBOT_CLASS(Robot3467_2012);

