#include <iostream>

#include "Constants.h"
#include "Plant.h"

Plant::Plant()
    : PositionX(rand() % (SCREEN_WIDTH - Plant::Largeur))
    , PositionY(rand() % (SCREEN_HEIGHT - Plant::Hauteur))
    , Timer(0)
    , Times(1)
    , GrowStady(0)
    , Randome(rand() % 10 + 1)
{}

void Plant::Update(long Millis) {
    Timer += Millis;
    if (Timer > Times * 1000) {
        if (Randome == 2) {
            if (GrowStady < 4)
                GrowStady++;
        }
        Times++;
    }
    Randome = rand() % 10 + 1;
}

void Plant::CropCollect() 
{
    GrowStady = 0;
}

double Plant::GetPositionX() const
{
    return PositionX;
}

double Plant::GetPositionY() const
{
    return PositionY;
}

int Plant::GetGrowStady() const
{
    return GrowStady;
}