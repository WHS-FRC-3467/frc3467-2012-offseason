#ifndef PRINT_LINE_H
#define PRINT_LINE_H

#include "../../CommandBase.h"

class PrintLine: public CommandBase {
public:
	PrintLine(const char *message, int line);
protected:
	const char *xmessage;
	int xline;
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
