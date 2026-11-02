#include "setup.h"
#include "pros/abstract_motor.hpp"
#include "pros/misc.h"
#include "pros/misc.hpp"

/*pros::Motor frontLeftMotor (-11, pros::v5::MotorGear::rpm_600, pros::MotorEncoderUnits::degrees);
pros::Motor backLeftMotor (-12, pros::v5::MotorGear::rpm_600, pros::MotorEncoderUnits::degrees);

pros::Motor frontRightMotor (19, pros::v5::MotorGear::rpm_600, pros::MotorEncoderUnits::degrees);
pros::Motor backRightMotor (20, pros::v5::MotorGear::rpm_600, pros::MotorEncoderUnits::degrees); */

pros::Controller master(pros::E_CONTROLLER_MASTER);

pros::MotorGroup RightMotors({-19, -20, -3, -4}, pros::v5::MotorGears::blue, pros::v5::MotorEncoderUnits::degrees);
pros::MotorGroup LeftMotors({-11, -12, -13, -14}, pros::v5::MotorGears::blue, pros::v5::MotorEncoderUnits::degrees);

//pros::MotorGroup Elevator({5, -6}, pros::v5::MotorGears::green, pros::v5::MotorEncoderUnits::degrees);

//pros::Motor Gripper(-7,pros::v5::MotorGears::green, pros::v5::MotorEncoderUnits::degrees);

//pros::Motor GripperPivot(8, pros::v5::MotorGears::green, pros::v5::MotorEncoderUnits::degrees);


pros::IMU imu (10);

//pros::adi::DigitalIn pushButton('E');

int direction;
int turn;

int leftPower;
int rightPower;

pros::Rotation vertical_encoder(-9);    // Mide adelante y atrás
pros::Rotation horizontal_encoder(18);  // Mide los lados (perpendicular)

// Ruedas de tracking asociadas a los encoders:
// Parámetros: (&encoder, diámetro_rueda, distancia_al_centro_en_pulgadas)
// Nota: Ajustamos el tamaño a NEW_2 asumiendo que usan las típicas rueditas de tracking de 2 pulgadas.
lemlib::TrackingWheel vertical_wheel(&vertical_encoder, lemlib::Omniwheel::NEW_2, -1.5); 
lemlib::TrackingWheel horizontal_wheel(&horizontal_encoder, lemlib::Omniwheel::NEW_2, 2.0);


// 1. Configuración de la transmisión del chasis
lemlib::Drivetrain drivetrain(
    &LeftMotors,                // Grupo de motores izquierdos
    &RightMotors,               // Grupo de motores derechos
    12.5,                       // Track Width (ancho del chasis de rueda a rueda en pulgadas)
    lemlib::Omniwheel::NEW_325, // Diámetro de tus ruedas de tracción (3.25 pulgadas)
    360,                        // RPM de salida reales de las ruedas (reducido mecánicamente)
    2                           // Multiplicador de persecución por defecto
);

// 2. Sensores asignados a la Odometría
lemlib::OdomSensors sensors(
    &vertical_wheel,   // Rueda vertical principal (mide avances)
    nullptr,           // Rueda vertical secundaria (no se usa)
    &horizontal_wheel, // Rueda horizontal (mide desplazamientos laterales)
    nullptr,           // Rueda horizontal secundaria (no se usa)
    &imu               // Sensor inercial principal (puerto 15)
);

// 3. Controladores de Movimiento PID (Valores base recomendados)
lemlib::ControllerSettings lateral_controller(
    10.0, // Proporcional (kP)
    0.0,  // Integral (kI)
    1.0,  // Derivativo (kD)
    3.0,  // Anti-windup
    1.0,  // Pequeño error admisible (pulgadas)
    100,  // Tiempo de espera para error pequeño (ms)
    3.0,  // Gran error admisible (pulgadas)
    500,  // Tiempo de espera para error grande (ms)
    20    // Slew rate (aceleración máxima)
);

lemlib::ControllerSettings angular_controller(
    2.0,  // Proporcional (kP)
    0.0,  // Integral (kI)
    10.0, // Derivativo (kD)
    3.0,  // Anti-windup
    1.0,  // Pequeño error admisible (grados)
    100,  // Tiempo de espera para error pequeño (ms)
    3.0,  // Gran error admisible (grados)
    500,  // Tiempo de espera para error grande (ms)
    0     // Slew rate (desactivado para giros)
);

// 4. Creación final del objeto chasis que enlaza todo
lemlib::Chassis chassis(drivetrain, lateral_controller, angular_controller, sensors);