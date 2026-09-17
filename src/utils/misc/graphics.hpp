#pragma once

#include <vector>

struct Vec2;

class Graphics {
public:
    // void connectDots(Vec2 a, Vec2 b);
    static std::vector<Vec2> bresenhamLine(int x0, int y0, int x1, int y1);

private:
};
