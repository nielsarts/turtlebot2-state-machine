//
// Created by Niels Arts on 18/01/2019.
//


#include "ObjectHandelingState.hpp"
#include "States.hpp"
#include "StateMonitor.hpp"

namespace StateMachine {

	ObjectHandelingState::ObjectHandelingState() :
		State("OBJECT HANDELING") {
	// TODO Auto-generated constructor stub

}

	ObjectHandelingState::~ObjectHandelingState() {
	// TODO Auto-generated destructor stub
}

void ObjectHandelingState::allDone(StateMonitor* context) {
	context->ChangeState(DoneState::Instance());

}

S_State ObjectHandelingState::instance;

S_State ObjectHandelingState::Instance() {
	if (!instance)
		instance = S_State(new IdleState());

	return instance;
}

}