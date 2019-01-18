//
// Created by Niels Arts on 18/01/2019.
//


#include "DoneState.hpp"
#include "States.hpp"
#include "StateMonitor.hpp"

namespace StateMachine{

	DoneState::DiscoveryBusState() :
		State("DONE") {
	// TODO Auto-generated constructor stub

}

	DoneState::~DiscoveryBusState() {
	// TODO Auto-generated destructor stub
}

void DoneState::allDone(StateMonitor* context) {

}

S_State DoneState::instance;

S_State DoneState::Instance() {
	if (!instance)
		instance = S_State(new DoneState());

	return instance;
}

} /* namespace bus_monitor */
//void DoneState::Stop(EcatBus* context) {
//	context->ChangeState(DeactivatedBusState::Instance(), S_BusState());
//}
//
//void DoneState::BusReady(EcatBus* context) {
//	context->ChangeState(DiscoveredBusState::Instance(),
//						 ActivatedBusState::Instance());
//}