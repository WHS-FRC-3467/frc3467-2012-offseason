#include "DSLCD.h"
#include "../Commands/DriverStation/UpdateLCD.h"
#include "../Robotmap.h"

DSLCD::DSLCD() : Subsystem("DSLCD")

{
	dsLCD = DriverStationLCD::GetInstance();
	count = 0;
}
    

/*
 * The default command will call LCDUpdate() periodically to
 * actually send the text to the Driver Station.
 */ 
void DSLCD::InitDefaultCommand()
{
	SetDefaultCommand(new UpdateLCD());
}

void DSLCD::LCDUpdate()
{
		dsLCD->Clear();
		dsLCD->UpdateLCD();
}

/**
 * Print formatted text to the Driver Station LCD text bufer.
 * 
 * @param line The line on the LCD to print to.
 * @param startingColumn The column to start printing to.  This is a 1-based number.
 * @param writeFmt The printf format string describing how to print.
 */
void DSLCD::Printf(DSLCD::Line line, INT32 startingColumn, const char *writeFmt, ...)
{
	va_list args;

	// Parse the arguments into the format string and save it all in a buffer
	va_start (args, writeFmt);
	{
		vsprintf(message, writeFmt, args);
	}
	va_end (args);

	// Write the contents of the buffer out to the DS LCD
	dsLCD->Printf((DriverStationLCD::Line)line, startingColumn, message);
}	

void DSLCD::PrintfLine(DSLCD::Line line, const char *writeFmt, ...)
{
	va_list args;

	// Parse the arguments into the format string and save it all in a buffer
	va_start (args, writeFmt);
	{
		vsprintf(message, writeFmt, args);
	}
	va_end (args);

	// Write the contents of the buffer out to the DS LCD
	dsLCD->PrintfLine((DriverStationLCD::Line)line, message);
}	

