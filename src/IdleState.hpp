//
// Created by Niels Arts on 18/01/2019.
//

#include "State.hpp"

namespace StateMachine {

class IdleState: public State {
private:
    static S_State instance;
protected:
    IdleState();
public:
    ~IdleState();
    virtual ~IdleState();
    virtual void allDone(StateMonitor* context);
    static S_State Instance();
};

}

