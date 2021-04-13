#include "Oeuf.h"

Oeuf::Oeuf(double PositionX, double PositionY)
    : Visible(true)
    , PositionX(PositionX)
    , PositionY(PositionY)
    , Timer(0)
{}

void Oeuf::Update(long Millis)
{
    // TODO : Faire changer la valeur de la variable `Visible` à
    // chaque 300 millisecondes

    Timer += Millis;

    if (Timer > 300) 
    {
        Visible = !Visible;
        Timer = 0;
    }
}

double Oeuf::GetPositionX() const
{
    return PositionX;
}

double Oeuf::GetPositionY() const
{
    return PositionY;
}

bool Oeuf::EstVisible() const
{
    return Visible;
}
