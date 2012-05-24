#ifndef SHOOTER_NO_FEED_H
#define SHOOTER_NO_FEED_H

#include "../../CommandBase.h"

/**
 * This is a simple command that makes sure the ball shooter feed roller  is doing nothing. It is the
 * default command for the Shooter Feed, so whenever no other running command requires
 * the Shooter Feed (via the {@link CommandBase#requires(edu.wpi.first.wpilibj.command.Subsystem)}
 * function) this command runs.
 */
class ShooterNoFeed: public CommandBase {
public:
	    ShooterNoFeed();
protected:
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
