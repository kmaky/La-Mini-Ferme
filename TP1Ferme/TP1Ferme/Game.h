#pragma once

#include <array>

#include "Partie.h"

class Game {
public:
    const int MS_PER_STEP = 30;

    Game();
    void Loop(SDL_Renderer* Renderer);

    void HandleInput(const SDL_Event& Event);
    void Update(long Millis);
    void Render(SDL_Renderer* Renderer) const;

protected:
    bool KeepPlaying;
    bool Pause;

    Partie PartieActuelle;
};
