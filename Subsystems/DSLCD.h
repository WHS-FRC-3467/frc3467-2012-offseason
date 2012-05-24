#ifndef DSLCD_H
#define DSLCD_H
#include "Commands/Subsystem.h"
#include "DriverStationLCD.h"
#include <strLib.h>
#include <string.h>



class DSLCD: public Subsystem {
private:
	int count;
	char message[64];
	DriverStationLCD *dsLCD;

public:
	enum Line {kShooter=0, kArm=1, kDrive=2, kCollector=3, kUser_Line5=4, kUser_Line6=5};
	
	DSLCD();
    void InitDefaultCommand();
    void LCDUpdate();
    void Printf(Line line, INT32 startingColumn, const char *writeFmt, ...);
    void PrintfLine(Line line, const char *writeFmt, ...);
};

#endif
