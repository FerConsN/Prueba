#include "myFunctions.h"
#include "pros/misc.h"
#include "setup.h"
#include <algorithm>
#include <tuple>

float distanceToAngle(float distance, float conversionFactor, float gearRatio){

    float angle = ((distance * 360) / conversionFactor) / gearRatio ; 

    return angle;
}
//24.6875

void moveGripperPivot(float angle){
    float position = angle * 3;
    GripperPivot.move_absolute(position, 200);
}

void gripMode(){
    //elevateToDistance(75);
    moveGripperPivot(70);
    Gripper.move_velocity(100);
}


void elevateToDistance(float distance){
    Elevator.move_absolute(0, 100);
        //distanceToAngle(distance, ELEVATOR_CONVERSION_FACTOR , 1), 100);
}

float applyDeadband(int value){
    if(std::abs(value) < DEADBAND){
        return 0;
    }
    return value;
}

std::tuple<int, int> driveSpeeds(){
    direction = applyDeadband(master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));
    turn = applyDeadband(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X));

    leftPower = direction + turn;
    rightPower = direction - turn;

    leftPower = std::clamp(leftPower, -127, 127) * 0.5;
    rightPower = std::clamp(rightPower, -127, 127) * 0.5;

    return {leftPower, rightPower};
}