//
// Created by Niels Arts on 18/01/2019.
//

#include "State.hpp"

namespace StateMachine {

State::State(std::string name) : name(name), parent() {
    // TODO Auto-generated constructor stub
}

State::State(std::string name, S_BusState parent) : name(name), parent(parent) {
    // TODO Auto-generated constructor stub

}

State::~State() {
    // TODO Auto-generated destructor stub
}

} /* namespace bus_monitor */
