#ifndef QUERY_SHOOTER_H
#define QUERY_SHOOTER_H

#include "../../CommandBase.h"


class queryShooter: public CommandBase {
public:
    queryShooter();

protected:
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
