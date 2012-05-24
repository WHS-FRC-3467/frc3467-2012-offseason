#ifndef SHIFTERS_DOWN_H
#define SHIFTERS_DOWN_H

#include "../../CommandBase.h"

class ShiftersShiftDown: public CommandBase {
public:
	    ShiftersShiftDown();
protected:
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
