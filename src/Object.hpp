//
// Created by Niels Arts on 17/01/2019.
//

#ifndef STATEMACHINE_OBJECT_HPP
#define STATEMACHINE_OBJECT_HPP

namespace StateMachine {

    typedef struct {
        double x, y, z;
    } Coordinate;

    class Object {
    public:
        Object(int ID_);
        virtual ~Object();
        int ID;
        int done;
        Coordinate xyz;
    };
}
#endif //STATEMACHINE_OBJECT_HPP
