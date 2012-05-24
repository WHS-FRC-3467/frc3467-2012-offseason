#ifndef SHOOTER_LOAD_H
#define SHOOTER_LOAD_H

#include "../../CommandBase.h"

/**
 * This is a simple command that runs the ball shooter roller.
 */
class ShooterLoad: public CommandBase {
public:
    ShooterLoad();

protected:
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
