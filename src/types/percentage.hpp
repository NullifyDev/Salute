#ifndef PERCENTAGE_HPP
#define PERCENTAGE_HPP
#pragma once

#include "vector.hpp"
// #include "../terminal.hpp"

struct Clamp;

struct Percentage
{
public:
    float sizeX, sizeY;
    u16 *refX, *refY;
    bool raw;
    Percentage(i16 x, i16 y, u16 *refx, u16 *refy, bool raw = false) : refX (refx), refY(refy), raw(raw)
    {
        this->sizeX = x != 0
            ? (x < 0 ? x + 100 : x) / 100.0f
            : 0;

        this->sizeY = y != 0
            ? (y < 0 ? y + 100 : y) / 100.0f
            : 0;
    }

    Vec2 ToVec2();
};
// x - (x % y)

#endif