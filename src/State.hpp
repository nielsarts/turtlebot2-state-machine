//
// Created by Niels Arts on 18/01/2019.
//

#include <string>
#include <memory>

namespace StateMachine {

class State;
typedef std::shared_ptr<State> S_State;
//class EcatBus;

class State {
protected:
    State(std::string name);
    State(std::string name, S_BusState parent);
public:
    std::string name;
    S_State parent;

    virtual ~State();
    virtual void Entry(EcatBus* context) = 0;
    virtual void Exit(EcatBus* context) = 0;
    virtual void Start(EcatBus* context) {};
    virtual void Stop(EcatBus* context) {};
    virtual void BusReady(EcatBus* context) {};
    virtual void BusNotReady(EcatBus* context) {};
};

} /* namespace bus_monitor */
