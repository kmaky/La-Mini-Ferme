#pragma once

class Gnome
{
public:
    Gnome();
    void Update(long Millis);

    double Distance(double X, double Y);

    double GetPositionX() const;
    double GetPositionY() const;
    bool LooksLeft() const;

    /*
      Notez : lorsqu'on parle d'encapsulation, on peut tolérer que les
      **constantes** soient publiques (il n'y a pas de danger qu'elles
      soient modifiées depuis l'extérieur de la classe)
    */
    static const int Largeur = 107;
    static const int Hauteur = 96;

private:
    double PositionX, PositionY;
    bool GoesLeft;
};
