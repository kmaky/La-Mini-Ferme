#pragma once

#include <array>

namespace Input
{
    const int Space = 0;
    const int Up = 1;
    const int Down = 2;
    const int Left = 3;
    const int Right = 4;

    extern std::array<bool, 5> PressedKeys;
}
