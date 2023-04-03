// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>

#include "rev/CANSparkMax.h"
#include "rev/CANSparkMaxLowLevel.h"
#include "frc/Joystick.h"
#include "frc/XboxController.h"
#include "frc/PneumaticHub.h"
#include "frc/Solenoid.h"
#include "frc/Compressor.h"
#include "frc/PowerDistribution.h"

#include "frc/BuiltInAccelerometer.h"
#include "frc/Timer.h"
#include "frc/GenericHID.h"


#define ID_MOTOR_FRONT   7
#define ID_COMPRESSOR    6
#define ID_Motor_1_Left  4
#define ID_Motor_2_Left  5
#define ID_Motor_3_Right 3
#define ID_Motor_4_Right 2
#define ID_PDH           8
#define USB_PORT_0       0
#define CHANEL_AXIS_X    0
#define CHANEL_AXIS_Y    1
#define CHANEL_AXIS_Z    2
#define CHANEL_AXIS_ROTATE_Z    3
#define THRESHOLD        0
#define PNEUMATIC_HUB_CHANNEL_0 0
#define PNEUMATIC_HUB_CHANNEL_3 3
#define LIMIT_MAX__RPM .80
#define LIMIT_MIN__RPM .20
/* #define OFF              0
#define ON               1 */

rev::CANSparkMax Motor_1(ID_Motor_1_Left,rev::CANSparkMaxLowLevel::MotorType::kBrushed);
rev::CANSparkMax Motor_2(ID_Motor_2_Left,rev::CANSparkMaxLowLevel::MotorType::kBrushed);
rev::CANSparkMax Motor_3(ID_Motor_3_Right,rev::CANSparkMaxLowLevel::MotorType::kBrushed);
rev::CANSparkMax Motor_4(ID_Motor_4_Right,rev::CANSparkMaxLowLevel::MotorType::kBrushed);
rev::CANSparkMax Motor_Front(ID_MOTOR_FRONT,rev::CANSparkMaxLowLevel::MotorType::kBrushed);
frc::Joystick    Controller(USB_PORT_0);
frc::PneumaticHub Compressor(ID_COMPRESSOR);
frc::Solenoid Solenoid(ID_COMPRESSOR, frc::PneumaticsModuleType::REVPH, PNEUMATIC_HUB_CHANNEL_0);
frc::Solenoid Solenoid_1(ID_COMPRESSOR, frc::PneumaticsModuleType::REVPH, PNEUMATIC_HUB_CHANNEL_3);
frc::Compressor Compressor_PH(ID_COMPRESSOR, frc::PneumaticsModuleType::REVPH);
frc::PowerDistribution PDH(ID_PDH, frc::PowerDistribution::ModuleType::kRev);
frc::BuiltInAccelerometer Acelera(frc::BuiltInAccelerometer::kRange_8G);
frc::Timer timer;
frc::GenericHID Controller_2(USB_PORT_0);

double power = 0.80;
double power_auto = 0.10;
double off = 0;
double wait_seconds = 4;
bool ON = true;

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;
  void SimulationInit() override;
  void SimulationPeriodic() override;

 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;
};
