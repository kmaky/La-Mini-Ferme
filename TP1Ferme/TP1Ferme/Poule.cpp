#include <iostream>

#include "Constants.h"
#include "Poule.h"

using namespace std;

Poule::Poule()
    : PositionX(rand() % (SCREEN_WIDTH - Poule::Largeur))
    , PositionY(rand() % (SCREEN_HEIGHT - Poule::Hauteur))
    , GoesLeft(false)
    , timer(0)
    , times(1)
{}

void Poule::Update(long Millis)
{
    if (GoesLeft) {
        PositionX -= 0.2 * Millis;
    }
    if (!GoesLeft) {
        PositionX += 0.2 * Millis;
    }
   
    /* 
       TODO : Changer la direction du mouvement des poules à toutes
       les 1000 millisecondes. Si jamais une poule essaie de sortir de
       l'écran, on inverse sa direction directement pour l'empêcher de
       sortir et on force sa position à re-rentrer dans l'écran.
    */

    timer += Millis;
    if (timer > times * 1000) {
        times++;
        this->GoesLeft = !this->GoesLeft;
    }

    if (PositionX < 0) {
        GoesLeft = false;
        times++;
    }

    if (PositionX > (SCREEN_WIDTH - Poule::Hauteur)) {
        times++;
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
