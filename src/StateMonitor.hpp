//
// Created by Niels Arts on 18/01/2019.
//

#ifndef STATEMACHINE_STATEMONITOR_HPP
#define STATEMACHINE_STATEMONITOR_HPP

#include "State.hpp"
#include "ObjectAdmin.hpp"

namespace StateMachine {

	class StateMonitor {
	private:
		S_State state;

	public:
		ObjectAdmin &object_admin;

		StateMonitor(ObjectAdmin &);

		virtual ~StateMonitor();

		void allDone();

		void ChangeState(S_State target);

	};

}

#endif
