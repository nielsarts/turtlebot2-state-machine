//
// Created by Niels Arts on 18/01/2019.
//


#include "StateMonitor.hpp"

#include "States.hpp"
#include <iostream>

namespace StateMachine {

EcatBus::EcatBus(EcatSlaveAdmin &t_SlaveAdmin) :
		SlaveAdmin(t_SlaveAdmin), state(DeactivatedBusState::Instance()) {
	// TODO Auto-generated constructor stub
	Entry(state, S_BusState());
}

StateMonitor::StateMonitor(ObjectAdmin &t_ObjectAdmin) :
		ObjectAdmin(t_ObjectAdmin), state(IdleState::Instance()) {
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

}
