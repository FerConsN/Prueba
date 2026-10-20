#pragma once
#include <tuple>

float distanceToAngle(float distance, float conversionFactor, float gearRatio);

void elevateToDistance(float distance);

void moveGripperPivot(float angle);

void gripMode();

void gripGrab();

void gripGive();

float applydeadband(int value);

std::tuple<int, int> driveSpeeds();