#include "setup.h"
#include "pros/abstract_motor.hpp"
#include "pros/misc.h"
#include "pros/misc.hpp"

/*pros::Motor frontLeftMotor (-11, pros::v5::MotorGear::rpm_600, pros::MotorEncoderUnits::degrees);
pros::Motor backLeftMotor (-12, pros::v5::MotorGear::rpm_600, pros::MotorEncoderUnits::degrees);

pros::Motor frontRightMotor (19, pros::v5::MotorGear::rpm_600, pros::MotorEncoderUnits::degrees);
pros::Motor backRightMotor (20, pros::v5::MotorGear::rpm_600, pros::MotorEncoderUnits::degrees); */

pros::Controller master(pros::E_CONTROLLER_MASTER);

pros::MotorGroup RightMotors({1, -2, 3, 4}, pros::v5::MotorGears::blue, pros::v5::MotorEncoderUnits::degrees);
pros::MotorGroup LeftMotors({-11, -12, 13, -14}, pros::v5::MotorGears::blue, pros::v5::MotorEncoderUnits::degrees);

pros::MotorGroup Elevator({5, -6}, pros::v5::MotorGears::green, pros::v5::MotorEncoderUnits::degrees);

pros::Motor Gripper(-7,pros::v5::MotorGears::green, pros::v5::MotorEncoderUnits::degrees);

pros::Motor GripperPivot(8, pros::v5::MotorGears::green, pros::v5::MotorEncoderUnits::degrees);


pros::IMU imu (15);

pros::adi::DigitalIn pushButton('E');

int direction;
int turn;

int leftPower;
int rightPower;
