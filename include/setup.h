#pragma once
#include "pros/motors.hpp"
#include "pros/motor_group.hpp"
#include "pros/imu.hpp"
#include "pros/adi.hpp"
#include "pros/rotation.hpp"
#include "lemlib/api.hpp"

//#define ELEVATOR_CONVERSION_FACTOR 1.75

#define DEADBAND 8.0

#define GEAR_RATIO 60/36

/*extern pros::Motor frontLeftMotor;
extern pros::Motor backLeftMotor;

extern pros::Motor frontRightMotor;
extern
pros::Motor backRightMotor;*/

extern pros::Controller master;

extern pros::MotorGroup LeftMotors;
extern pros::MotorGroup RightMotors;

//extern pros::MotorGroup Elevator;

//extern pros::Motor Gripper;

//extern pros::Motor GripperPivot;

extern pros::IMU imu;

//extern pros::adi::DigitalIn pushButton;

extern int direction;
extern int turn;

extern int leftPower;
extern int rightPower;

extern pros::Rotation vertical_encoder;
extern pros::Rotation horizontal_encoder;
extern lemlib::TrackingWheel vertical_wheel;
extern lemlib::TrackingWheel horizontal_wheel;


extern lemlib::Chassis chassis;
