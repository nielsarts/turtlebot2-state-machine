//
// Created by Niels Arts on 17/01/2019.
//
#include <iostream>
#include "ObjectAdmin.hpp"
#include <vector>

namespace StateMachine {

    ObjectAdmin::ObjectAdmin() {
        std::cout << "Object ObjectAdmin Constructed" << std::endl;
    }

    ObjectAdmin::~ObjectAdmin() {
        std::cout << "Object ObjectAdmin Destructed" << std::endl;
    }

    void ObjectAdmin::objectCreate(int ID) {
        Object *o = new Object(ID);
        objectVector.push_back(o);
    }

    void ObjectAdmin::objectFound(int ID, Coordinate xyz) {
        for (auto i : objectVector) {
            if (i->ID == ID) {
                i->xyz = xyz;
            }
        }
    }

    void ObjectAdmin::objectDone(int ID) {
        for (auto i : objectVector) {
            if (i->ID == ID) {
                i->done = 1;
            }
        }
    }

    int ObjectAdmin::getNextObject() {
        std::vector<int> left;
        for (auto i : objectVector) {
            if ((i->xyz.x != 0 || i->xyz.y != 0 || i->xyz.z != 0) && i->done == 0)
                left.push_back(i->ID);
        }
        if (left.size() == 0) {
            return 0;
        } else {
            for (auto i : left) {
                if (i == objectVector.back()->ID) {
                    if (numberObjects() - numberObjectsDone() == 1) {
                        return i;
                    } else {
                        return 0;
                    }
                } else {
                    return i;
                }
            }
        }
    }

    int ObjectAdmin::numberObjects() {
        return objectVector.size();
    }

    int ObjectAdmin::numberObjectsFound() {
        int count = 0;
        for (auto i: objectVector) {
            if (i->xyz.x != 0 || i->xyz.y != 0 || i->xyz.z != 0) {
                count++;
            }
        }
        return count;
    }

    int ObjectAdmin::numberObjectsDone() {
        int count = 0;
        for (auto i: objectVector) {
            if (i->done == 1) {
                count++;
            }
        }
        return count;
    }

    int ObjectAdmin::allObjectsFound() {
        for (auto i : objectVector) {
            if (i->xyz.x != 0 && i->xyz.y != 0 && i->xyz.z != 0) {
                return 0;
            }
        }
        return 1;

    }

    int ObjectAdmin::allObjectsDone() {
        for (auto i : objectVector) {
            if (i->done != true) {
                return 0;
            }
        }
        return 1;
    }
}