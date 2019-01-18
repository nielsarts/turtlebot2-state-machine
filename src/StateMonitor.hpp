//
// Created by Niels Arts on 18/01/2019.
//

#include "StateMonitor.hpp.hpp"
#include "ObjectAdmin.hpp"

namespace StateMachine {

	class StateMonitor {
	private:
		S_State state;

	public:
		ObjectAdmin &ObjectAdmin;

		StateMonitor(ObjectAdmin &);

		virtual ~StateMonitor();

		void allDone();

		void ChangeState(S_State target);

	};

}
