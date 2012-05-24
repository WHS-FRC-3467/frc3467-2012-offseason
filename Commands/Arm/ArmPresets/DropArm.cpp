#include "DropArm.h"

#include "SetArmPos.h"

DropArm::DropArm() {
	AddParallel(new SetArmPos(Arm::BOTTOM));
}
