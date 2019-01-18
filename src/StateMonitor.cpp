//
// Created by Niels Arts on 18/01/2019.
//


#include "StateMonitor.hpp"

#include "States.hpp"
#include <iostream>

namespace StateMachine {

StateMonitor::StateMonitor(ObjectAdmin &t_ObjectAdmin) :
		ObjectAdmin(t_ObjectAdmin) {
	// TODO Auto-generated constructor stub
}

StateMonitor::~StateMonitor() {
	// TODO Auto-generated destructor stub
}



void StateMonitor::allDone() {
	std::cout << state->name << ": allDone()" << std::endl;
	state->alldone(this);
}

void StateMonitor::ChangeState(S_State target) {
	std::cout << state->name << ": ChangeState: --> " << target->name << std::endl;
	state = target;
}

} /* namespace bus_monitor */
