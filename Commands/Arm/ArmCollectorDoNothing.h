#ifndef ARMCOLLECTOR_DO_NOTHING_H
#define ARMCOLLECTOR_DO_NOTHING_H

#include "../../CommandBase.h"

/**
 * This is a simple command that makes sure the ball collector is doing nothing. It is the
 * default command for the Collector, so whenever no other running command requires
 * the Collector (via the {@link CommandBase#requires(edu.wpi.first.wpilibj.command.Subsystem)}
 * function) this command runs.
 */
class ArmCollectorDoNothing: public CommandBase {
public:
	    ArmCollectorDoNothing();
protected:
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
