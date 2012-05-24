#ifndef SHOOTER_DO_NOTHING_H
#define SHOOTER_DO_NOTHING_H

#include "../../CommandBase.h"

class ShooterDoNothing: public CommandBase {
public:
	    ShooterDoNothing();
protected:
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
