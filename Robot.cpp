// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include "iostream"
#include <fmt/core.h>
#include <frc/smartdashboard/SmartDashboard.h>




void Robot::RobotInit() {

 
  Motor_1.RestoreFactoryDefaults(true);
  Motor_1.SetInverted(false);
  Motor_1.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);

  Motor_2.RestoreFactoryDefaults(true);
  Motor_2.SetInverted(false);
  Motor_2.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);

  Motor_3.RestoreFactoryDefaults(true);
  Motor_3.SetInverted(false);
  Motor_3.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);

  Motor_4.RestoreFactoryDefaults(true);
  Motor_4.SetInverted(false);
  Motor_4.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);

  Motor_Front.RestoreFactoryDefaults(true);
  Motor_Front.SetInverted(false);
  Motor_Front.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);

  Controller.SetZChannel(CHANEL_AXIS_ROTATE_Z);
  Controller.SetXChannel(0);

  PDH.ResetTotalEnergy();
  PDH.ClearStickyFaults();
  Compressor.ClearStickyFaults();
  // Compressor.MakeSolenoid(PNEUMATIC_HUB_CHANNEL_0);
  Compressor_PH.EnableDigital();
  Compressor_PH.Disable();
  
  
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
}

/**
 * This function is called every 20 ms, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {
}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  fmt::print("Auto selected: {}\n", m_autoSelected);

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {

 if(off < Controller_2.GetRawAxis(3)){
  //Fordward
    Motor_1.Set(-power * (Controller_2.GetRawAxis(3)));
    Motor_2.Set(-power * (Controller_2.GetRawAxis(3)));
    Motor_3.Set(power  * (Controller_2.GetRawAxis(3)));
    Motor_4.Set(power  * (Controller_2.GetRawAxis(3)));
  }else if(off < Controller_2.GetRawAxis(2)){
    //Turn right
    Motor_1.Set(power  * (Controller_2.GetRawAxis(2)));
    Motor_2.Set(power  * (Controller_2.GetRawAxis(2)));
    Motor_3.Set(-power * (Controller_2.GetRawAxis(2)));
    Motor_4.Set(-power * (Controller_2.GetRawAxis(2)));
  }else if(off < Controller_2.GetRawAxis(4)){
    //Turn left
    Motor_1.Set(-power * (Controller_2.GetRawAxis(4)));
    Motor_2.Set(-power * (Controller_2.GetRawAxis(4)));
    Motor_3.Set(-power * (Controller_2.GetRawAxis(4)));
    Motor_4.Set(-power * (Controller_2.GetRawAxis(4)));
  }else if(off > Controller_2.GetRawAxis(4)){
    // Revers
    Motor_1.Set(power * ((Controller_2.GetRawAxis(4)*(-1))) );
    Motor_2.Set(power * ((Controller_2.GetRawAxis(4)*(-1))) );
    Motor_3.Set(power * ((Controller_2.GetRawAxis(4)*(-1))) );
    Motor_4.Set(power * ((Controller_2.GetRawAxis(4)*(-1))) );
  }else{
    // Turn off
    Motor_1.Set(off);
    Motor_2.Set(off);
    Motor_3.Set(off);
    Motor_4.Set(off);
  }

  // Compresor 
  if(ON = Compressor_PH.GetPressureSwitchValue()){
    Compressor_PH.EnableDigital();
  }else{
    Compressor_PH.Disable();
  } 

  // Piston griper 
  if(Controller_2.GetRawButtonPressed(3)){
    Solenoid.Toggle();
  }

  // Motor griper 
  if(Controller_2.GetRawButton(5)){
    Motor_Front.Set(power);
  }else if(Controller_2.GetRawButton(6)){
    Motor_Front.Set(-.50);
  }else{
    Motor_Front.Set(off);
  }


  
}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {
  
  // Pruebas con configuración de control 
  if(off < Controller_2.GetRawAxis(3)){
    Motor_1.Set(-power * (Controller_2.GetRawAxis(3)));
    Motor_2.Set(-power * (Controller_2.GetRawAxis(3)));
    Motor_3.Set(power  * (Controller_2.GetRawAxis(3)));
    Motor_4.Set(power  * (Controller_2.GetRawAxis(3)));
  }else if(off < Controller_2.GetRawAxis(2)){
    Motor_1.Set(power  * (Controller_2.GetRawAxis(2)));
    Motor_2.Set(power  * (Controller_2.GetRawAxis(2)));
    Motor_3.Set(-power * (Controller_2.GetRawAxis(2)));
    Motor_4.Set(-power * (Controller_2.GetRawAxis(2)));
  }else if(off < Controller_2.GetRawAxis(4)){
    Motor_1.Set(-power * (Controller_2.GetRawAxis(4)));
    Motor_2.Set(-power * (Controller_2.GetRawAxis(4)));
    Motor_3.Set(-power * (Controller_2.GetRawAxis(4)));
    Motor_4.Set(-power * (Controller_2.GetRawAxis(4)));
  }else if(off > Controller_2.GetRawAxis(4)){
    Motor_1.Set(power * ((Controller_2.GetRawAxis(4)*(-1))) );
    Motor_2.Set(power * ((Controller_2.GetRawAxis(4)*(-1))) );
    Motor_3.Set(power * ((Controller_2.GetRawAxis(4)*(-1))) );
    Motor_4.Set(power * ((Controller_2.GetRawAxis(4)*(-1))) );
  }else{
    Motor_1.Set(off);
    Motor_2.Set(off);
    Motor_3.Set(off);
    Motor_4.Set(off);
  }

  if(ON = Compressor_PH.GetPressureSwitchValue()){
    Compressor_PH.EnableDigital();
  }else{
    Compressor_PH.Disable();
  } 

  if(Controller_2.GetRawButtonPressed(3)){
    Solenoid.Toggle();
  }

  if(Controller_2.GetRawButton(5)){
    Motor_Front.Set(power);
  }else if(Controller_2.GetRawButton(6)){
    Motor_Front.Set(-.50);
  }else{
    Motor_Front.Set(off);
  }


}

void Robot::SimulationInit() {}

void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {

  return frc::StartRobot<Robot>();
  
}
#endif
