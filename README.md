# turtlebot2-state-machine
[![Build Status](https://travis-ci.org/nielsarts/turtlebot2-state-machine.svg?branch=master)](https://travis-ci.org/nielsarts/turtlebot2-state-machine)
![](https://img.shields.io/github/license/nielsarts/turtlebot2-state-machine.svg?style=flat)

## Overview
Mirror of gitlab https://gitlab.twizzel.net/ros/turtlebot2-state-machine

This Packages is a state machine for the Turtlebot robot during Project Robotics at Amsterdam University of Applied Sciences. It's build to run with Robot Operation System, ROS, and catkin.

**Keywords:** turtlebot, state, machine, catkin, ros

### License

The source code is released under a [BSD 2-Clause license](/LICENSE).

**Author: Niels Arts, Niels.Arts@HvA.nl<br />**

The turtlebot2-state-machine package has been tested under [ROS] Kinetic and Ubuntu 16.04. This is research code, expect that it changes often and any fitness for a particular purpose is disclaimed.


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


## Usage

Describe the quickest way to run this software, for example:

Run the main node with

	roslaunch niels_state_machine launch.launch



## Bugs & Feature Requests

Please report bugs and request features using the [Issue Tracker](https://github.com/nielsarts/turtlebot2-state-machine/issues).


[ROS]: http://www.ros.org
