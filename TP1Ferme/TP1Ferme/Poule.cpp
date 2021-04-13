#include <iostream>

#include "Constants.h"
#include "Poule.h"

using namespace std;

Poule::Poule()
    : PositionX(rand() % (SCREEN_WIDTH - Poule::Largeur))
    , PositionY(rand() % (SCREEN_HEIGHT - Poule::Hauteur))
    , GoesLeft(false)
    , Timer(0)
    , Times(1)
    , PondUnOeuf(false)
{}

void Poule::Update(long Millis)
{
    if (GoesLeft) 
    {
        PositionX -= 0.2 * Millis;
    }
    if (!GoesLeft) 
    {
        PositionX += 0.2 * Millis;
    }
   
    /* 
       TODO : Changer la direction du mouvement des poules à toutes
       les 1000 millisecondes. Si jamais une poule essaie de sortir de
       l'écran, on inverse sa direction directement pour l'empêcher de
       sortir et on force sa position à re-rentrer dans l'écran.
    */

    

    Timer += Millis;
    if (Timer > Times * 1000 && rand() % 10 > 8) 
    {
        Times++;
        this->GoesLeft = !this->GoesLeft;
    }

    if (PositionX < 0) 
    {
        GoesLeft = false;
        Times++;
    }

    if (PositionX > (SCREEN_WIDTH - Poule::Hauteur)) 
    {
        Times++;
        GoesLeft = true;
    }

    /*
      TODO : La poule doit pondre un oeuf aux 8000 millisecondes.

      La façon la plus simple de représenter ça est d'avoir un état
      "bool PondUnOeuf" qui est vrai si la poule doit pondre un oeuf à
      un moment donné de la partie.  

      Dans l'objet `Partie`, on doit vérifier quelles poules doivent
      pondre, s'occuper de créer les oeufs nécessaires et de mettre la
      valeur de `PondUnOeuf` à false lorsque c'est fait.
    */

    if (Timer > 8000 && !PondUnOeuf) 
    {
        PondUnOeuf = true;
    }
}

bool Poule::LooksLeft() const
{
    return GoesLeft;
}

double Poule::GetPositionX() const
{
    return PositionX;
}

double Poule::GetPositionY() const
{
    return PositionY;
}

bool Poule::GetPondUnOeuf() const
{
    return PondUnOeuf;
}

void Poule::APondeUnOeuf()
{
    PondUnOeuf = false;
    Timer = 0;
    Times = 0;
}
