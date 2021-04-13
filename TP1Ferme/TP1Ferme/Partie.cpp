#include "Partie.h"

#include <algorithm>
#include <array>
#include <vector>

#include "Constants.h"
#include "Poule.h"
#include "Input.h"

#include "Plant.h"

Partie::Partie()
    : PartieFinie(false)
{
    //for(int i=0; i<9; i++)
    //    Oeufs.push_back(Oeuf{50.0 * i, 50.0 * i}); // TODO : SUPPRIMER CETTE LIGNE, c'est seulement un exemple
}

void Partie::Update(long Millis)
{
    // Si la partie n'est pas encore terminée, on fait avancer l'état
    // du jeu
    if (PartieFinie)
    {
        return;
    }


    Joueur.Update(Millis);

    // TODO : Mise à jour des plantes
    for (auto& P : Plants)
        for (auto& P1 : P)
            P1.Update(Millis);

    // TODO : Mise à jour des Poules
    // 
    for (int i = 0; i < Poules.size(); i++) {
        Poules[i].Update(Millis);
    }

    // TODO : Ajouter les oeufs qui sont pondus par les poules
    for (int i = 0; i < Poules.size(); i++) {
        if (Poules[i].GetPondUnOeuf()) {
            double x = Poules[i].GetPositionX();
            double y = Poules[i].GetPositionY();

            Oeufs.push_back(Oeuf{ x, y});

            Poules[i].APondeUnOeuf();
        }
    }

    // Mise à jour des oeufs
    for (auto& Oeuf : Oeufs)
    {
        Oeuf.Update(Millis);
    }

    /*
       Efface tous les oeufs à moins de 70 pixels de joueur lorsqu'on
       appuie sur Espace

       On jasera de ce code un peu plus tard dans la session... C'est
       normal si vous n'êtes pas 100% sûrs de ce qui se passe ici ;)
    */
    Oeufs.erase(
        std::remove_if(
            Oeufs.begin(), Oeufs.end(),
            [&](auto& O) {
                return Input::PressedKeys[Input::Space]
                    && Joueur.Distance(O.GetPositionX() + Oeuf::Largeur / 2, O.GetPositionY() + Oeuf::Hauteur / 2) < 70;
            }),
        Oeufs.end());

    for (auto& P : Plants)
        for (auto& P1 : P)
            if (Input::PressedKeys[Input::Space] && Joueur.Distance(P1.GetPositionX(), P1.GetPositionY()) < 70 && P1.GetGrowStady() == 4) {
                P1.CropCollect();
            }

    VerifierPartieFinie();
}

void Partie::Render(SDL_Renderer* Renderer) const
{
    // TODO: Dessin de l'arrière-plan de la bonne couleur
    int Rouge = 216;
    int Vert = 255;
    int Bleu = 211;
    SDL_SetRenderDrawColor(Renderer, Rouge, Vert, Bleu, 255);
    SDL_RenderClear(Renderer);


    // TODO: Dessin des plantes
    for (auto& P : Plants)
        for (auto& P1 : P)
            if (P1.GetGrowStady() != 0)
                Render::DrawSprite(Renderer, P1.GetGrowStady() == 2 ? Sprite::Plante2 : P1.GetGrowStady() == 3 ? Sprite::Plante3 : P1.GetGrowStady() == 4 ? Sprite::Plante4 : Sprite::Plante1, P1.GetPositionX(), P1.GetPositionY());

    // TODO: Dessin des oeufs
    for (auto& O : Oeufs)
        if (O.EstVisible())
            Render::DrawSprite(Renderer, Sprite::Oeuf, O.GetPositionX(), O.GetPositionY());

    // Dessin des poules
    for (auto& P : Poules)
        Render::DrawSprite(Renderer, P.LooksLeft() ? Sprite::ChickenLeft : Sprite::ChickenRight, P.GetPositionX(), P.GetPositionY());

    // Dessin du gnome
    Render::DrawSprite(Renderer, Joueur.LooksLeft() ? Sprite::GnomeLeft : Sprite::GnomeRight, Joueur.GetPositionX(), Joueur.GetPositionY());

    if (PartieFinie)
        Render::DrawSprite(Renderer, Sprite::GameOver, SCREEN_WIDTH / 2 - 300 / 2, SCREEN_HEIGHT / 2 - 120 / 2);
}

void Partie::VerifierPartieFinie()
{
    // TODO : La partie se termine quand il y a 25 choses ou plus à
    // ramasser (fraises/poules)

    int DeathCounter = 0;

    for (auto& O : Oeufs)
        DeathCounter++;

    for (auto& P : Plants)
        for (auto& P1 : P)
            if (P1.GetGrowStady() == 4)
                DeathCounter++;

    // Lorsque la partie est terminée, changez la variable :
    // PartieFinie = true;
    //
    // et allez ajouter 1000 nouveaux oeufs sur l'écran à des endroits
    // aléatoires

    if (DeathCounter >= 25) {
        PartieFinie = true;
        for (int i = 0; i < 31; i++)
            for (int j = 0; j < 31; j++)
                Oeufs.push_back(Oeuf{ (double)(rand() % (SCREEN_WIDTH - 10)), (double)(rand() % (SCREEN_HEIGHT - 10)) });
    }
}
