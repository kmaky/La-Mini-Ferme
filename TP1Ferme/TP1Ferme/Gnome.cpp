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
    if(Input::PressedKeys[Input::Right] && PositionX + 100 < SCREEN_WIDTH)
    {
        PositionX += 0.2 * Millis;
        GoesLeft = false;
    }
    else if(Input::PressedKeys[Input::Left] && PositionX > 0)
    {
        PositionX -= 0.2 * Millis;
        GoesLeft = true;
    }

    if(Input::PressedKeys[Input::Up] && PositionY > 0)
    {
        PositionY -= 0.2 * Millis;
    }
    else if(Input::PressedKeys[Input::Down] && PositionY + 100 < SCREEN_HEIGHT)
    {
        PositionY += 0.2 * Millis;
    }

    // TODO : Empêcher le Gnome de sortir de l'écran
}

// TODO : Calcul de la distance entre le gnome et une position (X, Y)
// sur l'écran
double Gnome::Distance(double X, double Y)
{
    double answer = (double)sqrt((X - PositionX - 50) * (X - PositionX - 50) + (Y - PositionY - 50) * (Y - PositionY - 50));

    return answer;
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
