//
// Created by Niels Arts on 18/01/2019.
//

#ifndef STATEMACHINE_IDLESTATE_HPP
#define STATEMACHINE_IDLESTATE_HPP

#include "State.hpp"

namespace StateMachine {

class IdleState: public State {
private:
    static S_State instance;
public:
    IdleState();
    virtual ~IdleState();
    virtual void allDone(StateMonitor* context);
    virtual void notDone(StateMonitor* context);
    static S_State Instance();
};

}

#endif
