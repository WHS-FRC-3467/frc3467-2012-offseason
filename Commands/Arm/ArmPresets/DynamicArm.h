#ifndef DYNAMICARM_H
#define DYNAMICARM_H
#include "../../../CommandBase.h"


class DynamicArm: public CommandBase {
public:
	DynamicArm();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:
	float opY;
};

#endif
