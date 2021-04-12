#include <SDL.h>
#include <string>
#include <array>

enum class Sprite
{
    GameOver,
    GnomeLeft,
    GnomeRight,
    ChickenLeft,
    ChickenRight,
    Oeuf,
    Plante1,
    Plante2,
    Plante3,
    Plante4,
};

namespace Render
{
    const int NB_SPRITES = static_cast<int>(Sprite::Plante4) + 1;
    
    const std::array<const char*, NB_SPRITES> Paths = {
        "imgs/game-over.bmp",
        "imgs/gnome-left.bmp",
        "imgs/gnome-right.bmp",
        "imgs/cotcot-left.bmp",
        "imgs/cotcot-right.bmp",
        "imgs/egg.bmp",
        "imgs/plante1.bmp",
        "imgs/plante2.bmp",
        "imgs/plante3.bmp",
        "imgs/plante4.bmp"
    };

    void LoadImgs(SDL_Renderer* Renderer);
    void FreeImgs();
    SDL_Texture* LoadImg(SDL_Renderer* Renderer, const char* src);
    void DrawTexture(SDL_Renderer* Renderer, SDL_Texture* Texture, int x, int y);

    void DrawSprite(SDL_Renderer* Renderer, Sprite S, double X, double Y);
}
