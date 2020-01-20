/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/smartdashboard.h>

#include "ColorRead.h"

#include "rev/ColorSensorV3.h"

class Robot : public frc::TimedRobot {

  static constexpr auto i2cPort = frc::I2C::Port::kMXP;

  rev::ColorSensorV3 m_colorSensor{i2cPort};

 public:
  void RobotPeriodic() {

    frc::Color detectedColor = m_colorSensor.GetColor();

    frc::SmartDashboard::PutNumber("Red", detectedColor.red);
    frc::SmartDashboard::PutNumber("Green", detectedColor.green);
    frc::SmartDashboard::PutNumber("Blue", detectedColor.blue);

    if (ColorRead::IsRed(detectedColor.red, detectedColor.green, detectedColor.blue))
    {
      frc::SmartDashboard::PutString("Color", "Red");
    }
    else
    {
      if (ColorRead::IsGreen(detectedColor.red, detectedColor.green, detectedColor.blue))
      {
        frc::SmartDashboard::PutString("Color", "Green");
      }
      else
      {
        if (ColorRead::IsBlue(detectedColor.red, detectedColor.green, detectedColor.blue))
        {
          frc::SmartDashboard::PutString("Color", "Blue");
        }
        else
        {
          if (ColorRead::IsYellow(detectedColor.red, detectedColor.green, detectedColor.blue))
          {
            frc::SmartDashboard::PutString("Color", "Yellow");
          }
          else
          {
            frc::SmartDashboard::PutString("Color", "None");
          }
        }
      }
    }

    uint32_t proximity = m_colorSensor.GetProximity();

    frc::SmartDashboard::PutNumber("Proximity", proximity);
  }
};

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif