#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>
#include <iostream>
#include <vector>

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

class ObjectAdmin {
public:
    ObjectAdmin();
    virtual ~ObjectAdmin();

    std::vector<Object*> objectVector;

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

ObjectAdmin::ObjectAdmin() {
    std::cout << "Object ObjectAdmin Constructed" << std::endl;
}

ObjectAdmin::~ObjectAdmin() {
    std::cout << "Object ObjectAdmin Destructed" << std::endl;
}

void ObjectAdmin::objectCreate(int ID) {
    Object* o = new Object(ID);
    objectVector.push_back(o);
}

void ObjectAdmin::objectFound(int ID, Coordinate xyz) {
    for(auto i : objectVector){
        if(i->ID == ID) {
            i->xyz = xyz;
        }
    }
}

void ObjectAdmin::objectDone(int ID) {
    for(auto i : objectVector){
        if(i->ID == ID) {
            i->done = 1;
        }
    }
}

int ObjectAdmin::getNextObject() {
    std::vector<int> left;
    for(auto i : objectVector) {
        if((i->xyz.x != 0 || i->xyz.y != 0 || i->xyz.z != 0) && i->done == 0)
            left.push_back(i->ID);
    }
    if (left.size() == 0){
        return 0;
    } else {
        for (auto i : left) {
            if (i == objectVector.back()->ID){
                if(numberObjects() - numberObjectsDone() == 1){
                    return i;
                }
                else {
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
    for(auto i: objectVector) {
        if(i->xyz.x != 0 || i->xyz.y != 0 || i->xyz.z != 0) {
            count++;
        }
    }
    return count;
}

int ObjectAdmin::numberObjectsDone() {
    int count = 0;
    for(auto i: objectVector) {
        if(i->done == 1) {
            count++;
        }
    }
    return count;
}

int ObjectAdmin::allObjectsFound() {
    for(auto i : objectVector) {
        if(i->xyz.x != 0 && i->xyz.y != 0 && i->xyz.z != 0){
            return 0;
        }
    }
    return 1;

}

int ObjectAdmin::allObjectsDone() {
    for(auto i : objectVector) {
        if(i->done != true){
            return 0;
        }
    }
    return 1;
}

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
    /**
     * The ros::init() function needs to see argc and argv so that it can perform
     * any ROS arguments and name remapping that were provided at the command line.
     * For programmatic remappings you can use a different version of init() which takes
     * remappings directly, but for most command-line programs, passing argc and argv is
     * the easiest way to do it.  The third argument to init() is the name of the node.
     *
     * You must call one of the versions of ros::init() before using any other
     * part of the ROS system.
     */
    ros::init(argc, argv, "niels_state_machine");

    /**
     * NodeHandle is the main access point to communications with the ROS system.
     * The first NodeHandle constructed will fully initialize this node, and the last
     * NodeHandle destructed will close down the node.
     */
    ros::NodeHandle n;

    /**
     * The advertise() function is how you tell ROS that you want to
     * publish on a given topic name. This invokes a call to the ROS
     * master node, which keeps a registry of who is publishing and who
     * is subscribing. After this advertise() call is made, the master
     * node will notify anyone who is trying to subscribe to this topic name,
     * and they will in turn negotiate a peer-to-peer connection with this
     * node.  advertise() returns a Publisher object which allows you to
     * publish messages on that topic through a call to publish().  Once
     * all copies of the returned Publisher object are destroyed, the topic
     * will be automatically unadvertised.
     *
     * The second parameter to advertise() is the size of the message queue
     * used for publishing messages.  If messages are published more quickly
     * than we can send them, the number here specifies how many messages to
     * buffer up before throwing some away.
     */
    ros::Publisher test = n.advertise<std_msgs::String>("test", 1000);

    ros::Rate loop_rate(10);

    /**
     * A count of how many messages we have sent. This is used to create
     * a unique string for each message.
     */
    std::cout << "Hello, World!" << std::endl;
    ObjectAdmin* object_admin = new ObjectAdmin();
    object_admin->objectCreate(1);
    object_admin->objectCreate(2);
    object_admin->objectCreate(3);
    object_admin->objectCreate(4);
    object_admin->objectCreate(5);

    Coordinate xyz;
    xyz.x = 111;
    xyz.y = 222;
    xyz.z = 333;

    object_admin->objectFound(1, xyz);
    object_admin->objectFound(2, xyz);
    object_admin->objectFound(3, xyz);
    object_admin->objectFound(4, xyz);
    object_admin->objectFound(5, xyz);


    for(auto i : object_admin->objectVector) {
        std::cout << "ID: " <<  i->ID << " X: " << i->xyz.x << " Y: " << i->xyz.y << " Z: " << i->xyz.z << " Done: " << i->done << std::endl;
    }

    std::cout << "Next Object: " << object_admin->getNextObject() << std::endl;
    object_admin->objectDone(object_admin->getNextObject());
    object_admin->objectDone(object_admin->getNextObject());
    object_admin->objectDone(object_admin->getNextObject());

    std::cout << "Next Object: " << object_admin->getNextObject() << std::endl;

    int count = 0;
    while (ros::ok())
    {
        /**
         * This is a message object. You stuff it with data, and then publish it.
         */
        std_msgs::String msg;

        std::stringstream ss;
        ss << "hello world " << count;
        msg.data = ss.str();

        ROS_INFO("%s", msg.data.c_str());

        /**
         * The publish() function is how you send messages. The parameter
         * is the message object. The type of this object must agree with the type
         * given as a template parameter to the advertise<>() call, as was done
         * in the constructor above.
         */
        test.publish(msg);

        ros::spinOnce();

        loop_rate.sleep();
        ++count;
    }


    return 0;
}