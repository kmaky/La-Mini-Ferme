#include <iostream>

#include <SDL.h>

#include "Game.h"
#include "Partie.h"
#include "Input.h"

using namespace std;

Game::Game()
    : KeepPlaying(true)
    , Pause(false)
{
}

/**
 * Main game Loop
 *
 * See
 * http://gameprogrammingpatterns.com/game-loop.html
 * https://gafferongames.com/post/fix_your_timestep/
 */
void Game::Loop(SDL_Renderer* Renderer)
{
    SDL_Event Event;

    long LastFrameTime = SDL_GetTicks() - MS_PER_STEP;
    long TimeAccumulator = 0;

    Render::LoadImgs(Renderer);

    while (KeepPlaying) {

        long FrameTime = SDL_GetTicks();
        long Dt = FrameTime - LastFrameTime;

        // Clamp dt to avoid the spiral of death when the game lags
        if (Dt > 100) Dt = 100;

        TimeAccumulator += Dt;

        // -- Events --
        while (SDL_PollEvent(&Event)) {
            HandleInput(Event);
        }

        // -- Update --
        while (TimeAccumulator >= MS_PER_STEP) {

            Update(MS_PER_STEP);

            TimeAccumulator -= MS_PER_STEP;
        }

        Update(TimeAccumulator);

        TimeAccumulator = 0;

        Render(Renderer);

        int Wait = FrameTime + MS_PER_STEP - SDL_GetTicks();

        if (Wait < 0) {
            cout << "WARNING: lag of " << -Wait << "ms" << endl;
        } else {
            SDL_Delay(Wait);
        }

        LastFrameTime = FrameTime;
    }

    Render::FreeImgs();
}

void Game::HandleInput(const SDL_Event& Event)
{
    switch (Event.type) {
    // Si on relâche une touche
    case SDL_KEYUP:
        switch(Event.key.keysym.sym) {
        case SDLK_LEFT:
            Input::PressedKeys[Input::Left] = false;
            break;
        case SDLK_RIGHT:
            Input::PressedKeys[Input::Right] = false;
            break;
        case SDLK_DOWN:
            Input::PressedKeys[Input::Down] = false;
            break;
        case SDLK_UP:
            Input::PressedKeys[Input::Up] = false;
            break;
        case SDLK_SPACE:
            Input::PressedKeys[Input::Space] = false;
            break;
        }
        break;

    // Si on presse une touche
    case SDL_KEYDOWN:
        switch(Event.key.keysym.sym) {
        case SDLK_LEFT:
            Input::PressedKeys[Input::Left] = true;
            break;
        case SDLK_RIGHT:
            Input::PressedKeys[Input::Right] = true;
            break;
        case SDLK_DOWN:
            Input::PressedKeys[Input::Down] = true;
            break;
        case SDLK_UP:
            Input::PressedKeys[Input::Up] = true;
            break;
        case SDLK_SPACE:
            Input::PressedKeys[Input::Space] = true;
            break;

        case SDLK_p: // Pause
            Pause = !Pause;
            break;

        case SDLK_ESCAPE:
            KeepPlaying = false;
            break;
        }
    }
}

void Game::Update(long Millis)
{
    if(Pause) return;

    PartieActuelle.Update(Millis);
}

void Game::Render(SDL_Renderer* Renderer) const
{
    PartieActuelle.Render(Renderer);
    
    SDL_RenderPresent(Renderer);
}
