#ifndef MANUALCONTROL
#define MANUALCONTROL

#include "../../../CommandBase.h"


class ManualArmControl: public CommandBase {
public:
	ManualArmControl();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:
	float top;
	float modifier;
	double point;
};

#endif
