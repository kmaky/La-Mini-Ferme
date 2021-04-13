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
      Notez : lorsqu'on parle d'encapsulation, on peut tol�rer que les
      **constantes** soient publiques (il n'y a pas de danger qu'elles
      soient modifi�es depuis l'ext�rieur de la classe)
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
