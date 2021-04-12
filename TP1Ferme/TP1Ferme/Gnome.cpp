#include <iostream>
#include <cmath>

#include "Gnome.h"
#include "Constants.h"
#include "Input.h"


Gnome::Gnome()
    : PositionX{SCREEN_WIDTH / 2}
    , PositionY{SCREEN_HEIGHT / 2}
    , GoesLeft{true}
{
}

void Gnome::Update(long Millis)
{
    if(Input::PressedKeys[Input::Right])
    {
        PositionX += 0.2 * Millis;
        GoesLeft = false;
    }
    else if(Input::PressedKeys[Input::Left])
    {
        PositionX -= 0.2 * Millis;
        GoesLeft = true;
    }

    if(Input::PressedKeys[Input::Up])
    {
        PositionY -= 0.2 * Millis;
    }
    else if(Input::PressedKeys[Input::Down])
    {
        PositionY += 0.2 * Millis;
    }

    // TODO : Empêcher le Gnome de sortir de l'écran
}

// TODO : Calcul de la distance entre le gnome et une position (X, Y)
// sur l'écran
double Gnome::Distance(double X, double Y)
{
    return 0.123456789;
}

double Gnome::GetPositionX() const
{
    return PositionX;
}

double Gnome::GetPositionY() const
{
    return PositionY;
}

bool Gnome::LooksLeft() const
{
    return GoesLeft;
}
