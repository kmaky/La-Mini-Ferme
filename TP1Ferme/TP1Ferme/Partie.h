#pragma once

#include <SDL.h>
#include <array>
#include <vector>

#include "Poule.h"
#include "Render.h"
#include "Gnome.h"
#include "Oeuf.h"

#include "Plant.h"

class Partie
{
public:
    Partie();

    void Update(long Millis);
    void Render(SDL_Renderer* Renderer) const;

    void VerifierPartieFinie();

private:
    bool PartieFinie;

    Gnome Joueur;
    std::array<Poule, 10> Poules;
    std::vector<Oeuf> Oeufs;

    // TODO : Ajouter une grille 8 lignes x 12 colonnes d'objets `Plante`
    std::array<std::array<Plant, 12>, 8> Plants;
};
