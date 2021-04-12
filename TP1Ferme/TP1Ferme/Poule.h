#pragma once

class Poule
{
public:
    Poule();
    void Update(long Millis);

    bool LooksLeft() const;
    double GetPositionX() const;
    double GetPositionY() const;

    /*
      Notez : lorsqu'on parle d'encapsulation, on peut tolérer que les
      **constantes** soient publiques (il n'y a pas de danger qu'elles
      soient modifiées depuis l'extérieur de la classe)
    */
    static const int Largeur = 54;
    static const int Hauteur = 56;

private:
    double PositionX, PositionY;
    bool GoesLeft;
};
