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
    , RandomeDirection(rand()%3 + 1)
{}

void Poule::Update(long Millis)
{
    if (RandomeDirection == 1) {
        PositionX -= 0.2 * Millis;
        GoesLeft = false;
    }
    else if (RandomeDirection == 2) {
        PositionX += 0.2 * Millis;
        GoesLeft = true;
    }
    else if (RandomeDirection == 3)
        PositionY += 0.2 * Millis;
    else if (RandomeDirection == 4)
        PositionY -= 0.2 * Millis;
   
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
        RandomeDirection = rand() % 5 + 1;
    }
    
    if (PositionX < 0) 
    {
        RandomeDirection = 2;
        Times++;
    }
    else if (PositionX > (SCREEN_WIDTH - Poule::Largeur)) 
    {
        RandomeDirection = 1;
        Times++;
    }
    else if (PositionY < 0)
    {
        RandomeDirection = 3;
        Times++;
    }
    else if (PositionY > (SCREEN_HEIGHT - Poule::Hauteur))
    {
        RandomeDirection = 4;
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
    if (PondUnOeuf && (RandomeDirection == 1)) {
        return true;
    }
    return false;
}

void Poule::APondeUnOeuf()
{
    PondUnOeuf = false;
    Timer = 0;
    Times = 0;
}
