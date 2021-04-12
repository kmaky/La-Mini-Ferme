#include "Render.h"

#include <iostream>

using namespace std;

namespace Render
{
    static std::array<SDL_Texture*, NB_SPRITES> Textures;

    void LoadImgs(SDL_Renderer* Renderer)
    {
        for(int i=0; i<NB_SPRITES; i++)
        {
            Textures[i] = LoadImg(Renderer, Paths[i]);
        }
    }

    void FreeImgs()
    {
        for(int i=0; i<NB_SPRITES; i++)
        {
            SDL_DestroyTexture(Textures[i]);
        }
    }
    
    /**
     * @see https://fr.wikibooks.org/wiki/Programmation_avec_la_SDL/Afficher_une_image
     */
    SDL_Texture* LoadImg(SDL_Renderer* Renderer, const char* src)
    {
        SDL_Surface* Surface = SDL_LoadBMP(src);

        if(!Surface)
        {
            cout << "Image loading error: " << SDL_GetError() << endl;
            return nullptr;
        }
        SDL_Texture* texture = SDL_CreateTextureFromSurface(Renderer, Surface);
        SDL_FreeSurface(Surface);

        return texture;
    }

    void DrawTexture(SDL_Renderer* Renderer, SDL_Texture* Texture, int X, int Y)
    {
        SDL_Rect position;
        position.x = X;
        position.y = Y;
        SDL_QueryTexture(Texture, NULL, NULL, &position.w, &position.h);
        SDL_RenderCopy(Renderer, Texture, NULL, &position);
    }

    void DrawSprite(SDL_Renderer* Renderer, Sprite S, double X, double Y)
    {
        DrawTexture(Renderer, Textures[static_cast<int>(S)], static_cast<int>(X), static_cast<int>(Y));
    }
}
