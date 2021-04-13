#pragma once

class Plant
{
public:
    Plant();
    void Update(long Millis);
    void CropCollect();

    double GetPositionX() const;
    double GetPositionY() const;

    int GetGrowStady() const;

    /*
      Notez : lorsqu'on parle d'encapsulation, on peut tolérer que les
      **constantes** soient publiques (il n'y a pas de danger qu'elles
      soient modifiées depuis l'extérieur de la classe)
    */
    static const int Largeur = 70;
    static const int Hauteur = 70;

private:
    double PositionX, PositionY;

    long Timer;
    long Times;

    int GrowStady;

    int Randome;
};
