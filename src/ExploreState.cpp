//
// Created by Niels Arts on 18/01/2019.
//


#include "ExploreState.hpp"
#include "States.hpp"
#include "StateMonitor.hpp"

namespace StateMachine {

	ExploreState::ExploreState() :
		State("EXPLORE") {
	// TODO Auto-generated constructor stub

}

	ExploreState::~ExploreState() {
	// TODO Auto-generated destructor stub
}

void ExploreState::newObject(StateMonitor* context) {
	context->ChangeState(ObjectHandelingState::Instance());

}

S_State ExploreState::instance;

S_State ExploreState::Instance() {
	if (!instance)
		instance = S_State(new IdleState());

	return instance;
}

}