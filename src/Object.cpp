//
// Created by Niels Arts on 17/01/2019.
//
#include <iostream>
#include "Object.hpp"

namespace StateMachine {

    Object::Object(int ID_) : ID(ID_) {
        std::cout << "Object Object " << ID << " Constructed" << std::endl;
        xyz.x = 0;
        xyz.y = 0;
        xyz.z = 0;
        done = 0;
    }

    Object::~Object() {
        std::cout << "Object Object " << ID << " Destructed" << std::endl;
    }

}