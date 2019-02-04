# turtlebot2-state-machine
![](https://img.shields.io/github/license/nielsarts/turtlebot2-state-machine.svg?style=flat)

## Overview
Mirror of gitlab https://gitlab.twizzel.net/ros/turtlebot2-state-machine

This Packages is a state machine for the Turtlebot robot during Project Robotics at Amsterdam University of Applied Sciences. It's build to run with Robot Operation System, ROS, and catkin.

**Keywords:** turtlebot, state, machine, catkin, ros

### License

The source code is released under a [BSD 2-Clause license](ros_package_template/LICENSE).

**Author: Niels Arts<br />
Affiliation: [ANYbotics](https://www.anybotics.com/)<br />
Maintainer: Péter Fankhauser, pfankhauser@anybotics.com**

The PACKAGE NAME package has been tested under [ROS] Kinetic and Ubuntu 16.04. This is research code, expect that it changes often and any fitness for a particular purpose is disclaimed.

[![Build Status](http://rsl-ci.ethz.ch/buildStatus/icon?job=ros_best_practices)](http://rsl-ci.ethz.ch/job/ros_best_practices/)


## Installation

### Building from Source

#### Dependencies

- [Robot Operating System (ROS)](http://wiki.ros.org) (middleware for robotics),


#### Building

First make sure you have followed the [ROS Installation instructions](http://wiki.ros.org/ROS/Installation) and be formular with [Catkin](http://wiki.ros.org/catkin)

To build from source, clone the latest version from this repository into your catkin workspace and compile the package using

1. Clone this Repository insice your catkin_ws
```zsh
cd catkin_ws/src
git clone https://github.com/nielsarts/turtlebot2-state-machine.git
```
2. Make the packige from your workspace
```zsh
cd ../
catkin_make
```


### Unit Tests

Run the unit tests with

	catkin_make run_tests_ros_package_template


## Usage

Describe the quickest way to run this software, for example:

Run the main node with

	roslaunch ros_package_template ros_package_template.launch
  

## Launch files

* **launch_file_1.launch:** shortly explain what is launched (e.g standard simulation, simulation with gdb,...)

     Argument set 1

     - **`argument_1`** Short description (e.g. as commented in launch file). Default: `default_value`.

    Argument set 2

    - **`...`**

* **...**

## Nodes

### niels_state_machine_node


#### Subscribed Topics

...

#### Published Topics

...


## Bugs & Feature Requests

Please report bugs and request features using the [Issue Tracker](https://github.com/nielsarts/turtlebot2-state-machine/issues).


[ROS]: http://www.ros.org
