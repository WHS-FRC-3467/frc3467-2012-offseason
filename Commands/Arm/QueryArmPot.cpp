#include "QueryArmPot.h"


QueryArmPot::QueryArmPot() {
}
void QueryArmPot::Initialize(){
}


void QueryArmPot::Execute(){
	arm->ReturnPIDInput();
}


bool QueryArmPot::IsFinished(){
		return false;
}
	
void QueryArmPot::End(){
}
	
void QueryArmPot::Interrupted(){
	
}
