//
// Created by Niels Arts on 18/01/2019.
//

#ifndef STATEMACHINE_STATE_HPP
#define STATEMACHINE_STATE_HPP

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
        virtual void newObject(StateMonitor* context) {};
        virtual void objectFinished(StateMonitor* context) {};
        virtual void notDone(StateMonitor* context) {};
        virtual void start(StateMonitor* context) {};
    };

}

#endif