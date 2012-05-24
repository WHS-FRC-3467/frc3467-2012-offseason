#include "StowArm.h"

#include "SetArmPos.h"

StowArm::StowArm() {
     AddParallel(new SetArmPos(Arm::STOW));
}
