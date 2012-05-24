#ifndef BALLCOLLECTOR_EJECT_H
#define BALLCOLLECTOR_EJECT_H

#include "../../CommandBase.h"


class ArmEject: public CommandBase {
public:
   ArmEject();

protected:
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
