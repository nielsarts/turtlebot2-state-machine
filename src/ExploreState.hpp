//
// Created by Niels Arts on 18/01/2019.
//

#ifndef STATEMACHINE_EXPLORESTATE_HPP
#define STATEMACHINE_EXPLORESTATE_HPP

#include "State.hpp"

namespace StateMachine {

class ExploreState: public State {
private:
    static S_State instance;
public:
    ExploreState();
    virtual ~ExploreState();
    virtual void allDone(StateMonitor* context);
    static S_State Instance();
};

}

#endif
