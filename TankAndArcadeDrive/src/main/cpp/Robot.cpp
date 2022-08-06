// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc/XboxController.h>
#include <frc/TimedRobot.h>
#include <frc/motorcontrol/Victor.h>
#include <frc/motorcontrol/Spark.h>

/**
 * This sample program shows how to control a motor using a joystick. In the
 * operator control part of the program, the joystick is read and the value is
 * written to the motor.
 *
 * Joystick analog values range from -1 to 1 and speed controller inputs as
 * range from -1 to 1 making it easy to work together.
 */
class Robot : public frc::TimedRobot {
 public:
  void MoveTank(double left, double right)
  {
    m_motorL.Set(left);
    //m_motorL2.Set(left);
    m_motorR.Set(right);
    //m_motorR2.Set(right);
  }

  void MoveArcade(double X, double Y)
  {
    double leftY = Y + X;
    double rightY = Y - X;
    MoveTank(leftY, rightY);
  }

  void TeleopPeriodic() override 
  {
    MoveArcade(-m_stick.GetLeftY()/2, m_stick.GetRightX()/2);

    m_shoot1.Set(-m_stick.GetRightTriggerAxis());
    // m_shoot2.Set(m_stick.GetRightTriggerAxis());
    // m_shoot3.Set(m_stick.GetRightTriggerAxis());
    // m_shoot4.Set(m_stick.GetRightTriggerAxis());

    if(m_stick.GetAButton())
    {
      m_turret.Set(1);
    }
    if(m_stick.GetBButton())
    {
      m_turret.Set(-1);
    }
    if(m_stick.GetAButtonReleased() || m_stick.GetBButtonReleased())
    {
      m_turret.Set(0.0);
    }

    if(m_stick.GetXButton())
    {
      m_load.Set(1);
    }
    if(m_stick.GetYButton())
    {
      m_load.Set(-1);
    }
    if(m_stick.GetXButtonReleased() || m_stick.GetYButtonReleased())
    {
      m_load.Set(0.0);
    }

    // if(m_stick.GetBButton())
    // {
    //   m_loadBottom.Set(-1);
    //   m_loadMid.Set(1);
    //   m_loadTop.Set(1);
    // }
    // if(m_stick.GetBButton() && m_stick.GetRightBumper())
    // {
    //   m_loadBottom.Set(1);
    //   m_loadMid.Set(-1);
    //   m_loadTop.Set(-1);
    // }

    // if(m_stick.GetBButtonReleased())
    // {
    //   m_loadBottom.Set(0);
    //   m_loadMid.Set(0);
    //   m_loadTop.Set(0);
    // }
  }

 private:
  frc::XboxController m_stick{0};
  frc::Spark m_motorL{2};
  frc::Spark m_motorR{3};
  // frc::Victor m_motorL2{1};
  // frc::Victor m_motorR2{4};

  frc::Spark m_load{9};
  // frc::Victor m_loadMid{4};
  // frc::Victor m_loadTop{6};

  frc::Spark m_shoot1{5};
  // frc::Victor m_shoot2{5};
  // frc::Victor m_shoot3{7};
  // frc::Victor m_shoot4{8};

  frc::Spark m_turret{4};
};

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
