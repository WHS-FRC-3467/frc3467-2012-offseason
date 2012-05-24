#ifndef SHOOTER_LOAD_TIMED_H
#define SHOOTER_LOAD_TIMED_H

#include "../../CommandBase.h"

/**
 * This is a simple command that runs the ball shooter roller.
 */
class ShooterLoadTimed: public CommandBase {
public:
    ShooterLoadTimed(float timeout);

protected:
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
