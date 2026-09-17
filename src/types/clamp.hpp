#ifndef CLAMP_HPP
#define CLAMP_HPP
#pragma once

// #include <variant>

#include <cmath>

#include "percentage.hpp"

struct Clamp
{
    // Clamp() : scale(Percentage(0, 0, NULL, NULL)) {
    //     this->min = Vec2(
    //         static_cast<u16>(0),
    //         static_cast<u16>(0)
    //     );
    //     this->max = Vec2(
    //         static_cast<u16>(0),
    //         static_cast<u16>(0)
    //     );
    // }

    Clamp(Vec2 min, Percentage scale, Vec2 max) : min(min), max(max), scale(scale)
    {
        i16 x, y;

        x = std::abs(scale.sizeX) * (*scale.refX);
        if (x > max.x) x = max.x;
        if (x < min.x) x = min.x;

        y = std::abs(scale.sizeY) * (*scale.refY);
        if (y > max.y) y = max.y;
        if (y < min.y) y = min.y;

        // printf("[CLAMP]: %d:%d", x, y);
        // printf("[CLAMP]: min(%d:%d) scale(%d*%f, %d*%f) max(%d:%d) | %d:%d\n", min.x, min.y, *scale.refX, scale.sizeX, *scale.refY, scale.sizeY, max.x, max.y, x, y);
    }

    u16 getX() const;
    u16 getY() const;

    Vec2 min, max;
    Percentage scale;
};

#endif