//
// Created by Niels Arts on 17/01/2019.
//

#ifndef STATEMACHINE_OBJECTADMIN_HPP
#define STATEMACHINE_OBJECTADMIN_HPP

#include <vector>
#include "Object.hpp"

namespace StateMachine {

    class ObjectAdmin {
    public:
        ObjectAdmin();

        virtual ~ObjectAdmin();

        std::vector<Object *> objectVector;

        void objectCreate(int ID);

        void objectFound(int ID, Coordinate xyz);

        void objectDone(int ID);

        int getNextObject();

        int numberObjects();

        int numberObjectsFound();

        int numberObjectsDone();

        int allObjectsFound();

        int allObjectsDone();
    };
}

#endif //STATEMACHINE_OBJECTADMIN_HPP
