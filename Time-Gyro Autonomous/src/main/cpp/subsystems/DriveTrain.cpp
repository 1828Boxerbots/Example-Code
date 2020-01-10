/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveTrain.h"

DriveTrain::DriveTrain() : Subsystem("ExampleSubsystem") {}
//Code that only needs to run once when the code first starts up; Put this is initialize for commands
void DriveTrain::Initialize()
{
  m_gyro.Calibrate();
  m_gyro.Reset();
}
//Code that needs to run as soon as code starts; Put this in execute for commands
/*void DriveTrain::IsRunning()
{
  double currentAngle = m_gyro.GetAngle();
  SmartDashboard::PutNumber("Gyro Value", currentAngle);
}
*/
//turns on motors 
void DriveTrain::Forward()
{
  m_motorLeft.Set(LeftLimit);
  m_motorRight.Set(RightLimit);
}
//Stops motors
void DriveTrain::StopMotors()
{
  m_motorLeft.Set(0.0);
  m_motorRight.Set(0.0);
}
void DriveTrain::TurnLeft()
{
  m_motorLeft.Set(-LeftLimit);
  m_motorRight.Set(RightLimit);
}
void DriveTrain::TurnRight()
{
  m_motorLeft.Set(LeftLimit);
  m_motorRight.Set(-RightLimit);
}
//Moves motor with seconds
void DriveTrain::ForwardInSeconds(double timeLimit)
{
   Forward(); 
  frc::Timer timer;
  double startTime = timer.Get();
  while( timer.Get() - startTime < timeLimit)
  {
    //Puts start time and time limit in smart dashboard just in case
    SmartDashboard::PutNumber("Start Time", startTime);
    SmartDashboard::PutNumber("Time Limit", timeLimit);
  }
  StopMotors();
}
//Moves robot a certain degrees
void DriveTrain::TurnInDegrees(double angle)
{
  double startAngle = m_gyro.GetAngle();
  SmartDashboard::PutNumber("Gyro Value", startAngle);
  if (angle < 0.0)
  {
    TurnLeft();
    while (m_gyro.GetAngle() - startAngle > angle){}
  }
  else 
  {
    TurnRight();
    while (m_gyro.GetAngle() - startAngle < angle){}
  }
  StopMotors();
}
void DriveTrain::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
