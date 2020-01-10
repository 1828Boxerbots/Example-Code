/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoHouse.h"
#include "subsystems/DriveTrain.h"
#include <Robot.h>
AutoHouse::AutoHouse() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&Robot::m_driveTrain);
}

// Called just before this Command runs the first time
void AutoHouse::Initialize() 
{
Robot::m_driveTrain.Initialize();
}

// Called repeatedly when this Command is scheduled to run
void AutoHouse::Execute() 
{
  if (m_isRunning == true)
  {
    return;
  }

//  while(m_isRunning != true) {}
  m_isRunning = true;

  Robot::m_driveTrain.ForwardInSeconds(5.0);
//Wait(5.0);
/*Robot::m_driveTrain.TurnInDegrees(45.0);
Robot::m_driveTrain.ForwardInSeconds(3.0);
Wait(3.0);
TurnInDegrees(90.0);
ForwardInSeconds(3.0);
Wait(3.0);
TurnInDegrees(45.0);
ForwardInSeconds(5.0);
Wait(5.0);
TurnInDegrees(90.0);
ForwardInSeconds(3.0);
Wait(3.0);
*/
Robot::m_driveTrain.StopMotors();
//m_isRunning = false;
}

// Make this return true when this Command no longer needs to run execute()
bool AutoHouse::IsFinished() 
{ 
  return true; 
}

// Called once after isFinished returns true
void AutoHouse::End() 
{
  Robot::m_driveTrain.StopMotors();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoHouse::Interrupted() {}
