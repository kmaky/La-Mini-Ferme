#pragma once

class Oeuf
{
public:
    Oeuf(double PositionX, double PositionY);
    void Update(long Millis);

    double GetPositionX() const;
    double GetPositionY() const;
    bool EstVisible() const;

    static const int Largeur = 12;
    static const int Hauteur = 16;

private:
    bool Visible;
    double PositionX, PositionY;
    long Timer;
};
