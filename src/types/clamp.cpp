#include "clamp.hpp"

u16 Clamp::getX() const {
    u16 maxX = this->max.getx(), minX = this->min.getx(),
        res = 0;

    res = round(this->scale.sizeX * (*this->scale.refX));
    if (res > maxX) res = maxX;
    if (res < minX) res = minX;

    return res;
}

u16 Clamp::getY() const
{
    u16 maxY = this->max.gety(), minY = this->min.gety(),
        res = 0;

    res = round(this->scale.sizeY * (*this->scale.refY));
    if (res > maxY) res = maxY;
    if (res < minY) res = minY;

    if (this->scale.raw) (res)--;

    return res;
}