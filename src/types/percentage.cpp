#include "percentage.hpp"

Vec2 Percentage::ToVec2()
{
    return {
        static_cast<u16>(round(this->sizeX * (*refX))),
        static_cast<u16>(round(this->sizeY * (*refY)))
    };
}