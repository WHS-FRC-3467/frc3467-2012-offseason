#ifndef ARM_COLLECT_H
#define ARM_COLLECT_H

#include "../../CommandBase.h"


class ArmCollect: public CommandBase {
public:
    ArmCollect();

protected:
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
