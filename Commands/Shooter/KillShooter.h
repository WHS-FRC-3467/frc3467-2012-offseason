#ifndef KILL_SHOOTER_H
#define KILL_SHOOTER_H

#include "../../CommandBase.h"

class KillShooter: public CommandBase {
public:
	    KillShooter();
protected:
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
