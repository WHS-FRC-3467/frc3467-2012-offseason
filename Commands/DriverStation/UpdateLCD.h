#ifndef UPDATE_LCD_H
#define UPDATE_LCD_H

#include "Timer.h"
#include "../../CommandBase.h"

class UpdateLCD: public CommandBase {
public:
	UpdateLCD();
protected:
	double m_interval;
	double m_lastUpdate;

	virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
