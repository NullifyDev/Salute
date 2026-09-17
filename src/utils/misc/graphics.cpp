#include "graphics.hpp"

#include <cstdlib>
#include <vector>

#include "types/vector.hpp"

std::vector<Vec2> Graphics::bresenhamLine(int x0, int y0, int x1, int y1) {
    // Vec2 *points = static_cast<Vec2*>(malloc(sizeof(Vec2) * (abs(x1 - x0) + abs(y1 - y0) + 1)));
    std::vector<Vec2> points = std::vector<Vec2>();
    int pointCount = 0,
        dx = abs(x1 - x0),
        dy = abs(y1 - y0),
        sx = x0 < x1 ? 1 : -1,
        sy = y0 < y1 ? 1 : -1,
        err = dx - dy;

    while (1) {
        Vec2 point;
        point.x = x0;
        point.y = y0;
        points[pointCount++] = point;
        if (x0 == x1 && y0 == y1) break;
        int e2 = err << 1;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
    return points;
}