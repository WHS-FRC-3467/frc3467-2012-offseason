#ifndef SHOOTER_UNLOAD_H
#define SHOOTER_UNLOAD_H

#include "../../CommandBase.h"


class ShooterUnload:public CommandBase {
public:
    ShooterUnload();

protected:
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
