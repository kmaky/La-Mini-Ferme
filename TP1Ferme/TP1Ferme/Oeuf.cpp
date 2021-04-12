#include "Oeuf.h"

Oeuf::Oeuf(double PositionX, double PositionY)
    : Visible(true)
    , PositionX(PositionX)
    , PositionY(PositionY)
{}

void Oeuf::Update(long Millis)
{
    // TODO : Faire changer la valeur de la variable `Visible` à
    // chaque 300 millisecondes
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
