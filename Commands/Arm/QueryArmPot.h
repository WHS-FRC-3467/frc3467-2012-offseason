#ifndef QUERY_ARM_POT_H
#define QUERY_ARM_POT_H

#include "../../CommandBase.h"


class QueryArmPot: public CommandBase {
public:
	QueryArmPot();
protected:
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
