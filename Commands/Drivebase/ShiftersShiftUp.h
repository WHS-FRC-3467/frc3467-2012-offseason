#ifndef SHIFTERS_UP_H
#define SHIFTERS_UP_H

#include "../../CommandBase.h"

class ShiftersShiftUp: public CommandBase {
public:
	    ShiftersShiftUp();
protected:
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
