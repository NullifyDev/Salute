#pragma once

#include <vector>

#include "header.hpp"
#include "types/vector.hpp"
#include "utils/misc/graphics.hpp"

struct Vec2;

class Line {
    Line(UIElement brush, Vec2 src, Vec2 dst) :
        Brush(brush),
        Points(std::vector(Graphics::bresenhamLine(src.x, src.y, dst.x, dst.y))) {}


private:
    UIElement Brush;
    std::vector<Vec2> Points;
};
