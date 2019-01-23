//
// Created by Niels Arts on 18/01/2019.
//

#include <string>
#include <memory>

namespace StateMachine {

    class State;

    typedef std::shared_ptr<State> S_State;

    class StateMonitor;

    class State {
    protected:
        State(std::string name);

    public:
        std::string name;

        virtual ~State();

//    virtual void Start(StateMonitor* context) {};
//    virtual void Stop(StateMonitor* context) {};
//    virtual void BusReady(StateMonitor* context) {};
        virtual void allDone(StateMonitor* context) {};
    };

}