//
// Created by Niels Arts on 18/01/2019.
//

#ifndef STATEMACHINE_OBJECTHANDELINGSTATE_HPP
#define STATEMACHINE_OBJECTHANDELINGSTATE_HPP

#include "State.hpp"

namespace StateMachine {

class ObjectHandelingState: public State {
private:
    static S_State instance;
public:
    ObjectHandelingState();
    virtual ~ObjectHandelingState();
    virtual void objectFinished(StateMonitor* context);
    static S_State Instance();
};

}

#endif
