//
// Created by Niels Arts on 18/01/2019.
//

#include "State.hpp"


namespace StateMachine {

class DoneState: public State {
private:
    static S_State instance;
protected:
public:
    DoneState();
    virtual ~DoneState();
    virtual void allDone(StateMonitor* context);
    static S_State Instance();
};

}
