//
// Created by Niels Arts on 18/01/2019.
//

#include "StateMonitor.hpp"

namespace StateMachine {

class DoneState: public State {
private:
    static S_State instance;
public:
    DoneState();
    virtual ~DoneState();
    virtual void allDone(StateMonitor* context);
    static S_State Instance();
};

} /* namespace bus_monitor */

