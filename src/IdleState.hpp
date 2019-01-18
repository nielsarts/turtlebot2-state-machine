//
// Created by Niels Arts on 18/01/2019.
//

#include "StateMonitor.hpp"

namespace StateMachine {

class IdleState: public State {
private:
    static S_State instance;
public:
    IdleState();
    virtual ~IdleState();
    virtual void allDone(StateMonitor* context);
    static S_State Instance();
};

} /* namespace bus_monitor */

