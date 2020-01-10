/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/Spark.h>
#include <frc/ADXRS450_Gyro.h>
#include <RobotMap.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <opencv2/flann/Timer.h>

using namespace frc;
class DriveTrain : public frc::Subsystem {
 private:
 //Variables that needs ports
  Spark m_motorLeft{PWM_RIGHTMOTOR};
  Spark m_motorRight{PWM_LEFTMOTOR};
  ADXRS450_Gyro m_gyro{SPI::Port::kOnboardCS0};
  //variables for random things
  const double LeftLimit = .5;
  const double RightLimit = -.5;
  
 public:
  DriveTrain();
  void TurnRight();
  void TurnLeft();
  void Initialize();
  void IsRunning();
  void Forward();
  void StopMotors();
  void ForwardInSeconds(double timeLimit);
  void TurnInDegrees(double angle);
  void InitDefaultCommand() override;
};
