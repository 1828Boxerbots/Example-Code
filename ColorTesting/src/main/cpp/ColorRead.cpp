/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "ColorRead.h"

ColorRead::ColorRead() {}

// This method will be called once per scheduler run
void ColorRead::Periodic() {}

bool ColorRead::IsRed(double R, double G, double B) 
{
    if( R >= .45 && R <= .55)
    {
        if( G >= .3 && G <= .4)
        {
            if (B >= .08 && B <= .18)
            {
            return true; 
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool ColorRead::IsGreen(double R, double G, double B) 
{
    if( R >= .11 && R <= .21)
    {
        if( G >= .53 && G <= .63)
        {
        if ( B >= .2 && B <= .3)
            {
                return true; 
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool ColorRead::IsBlue(double R, double G, double B) 
{
    if( R >= .07 && R <= .17)
    {
        if( G >= .38 && G <= .48)
        {
            if (B >= .41 && B <= .51)
            {
            return true; 
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool ColorRead::IsYellow(double R, double G, double B) 
{
    if( R >= .25 && R <= .35)
    {
        if( G >= .51 && G <= .61)
        {
            if (B >= .08 && B <= .25)
            {
            return true; 
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
