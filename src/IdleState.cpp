//
// Created by Niels Arts on 18/01/2019.
//


#include "IdleState.hpp"
#include "States.hpp"
#include "StateMonitor.hpp"

namespace StateMachine{

	IdleState::IdleState() :
		State("IDLE") {
	// TODO Auto-generated constructor stub

}

	IdleState::~IdleState() {
	// TODO Auto-generated destructor stub
}

void IdleState::allDone(StateMonitor* context) {
	context->ChangeState(DoneState::Instance());

}

S_State IdleState::instance;

S_State IdleState::Instance() {
	if (!instance)
		instance = S_State(new IdleState());

	return instance;
}

}