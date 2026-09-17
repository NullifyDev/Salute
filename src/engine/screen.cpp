#include "screen.hpp"

fVec2 Engine::Screen::ToDotProduct(Vec2 point) const {
    return fVec2(
       static_cast<float>(((point.x+1)/2)*this->Size.x),
       static_cast<float>((point.y    /2)*this->Size.y)
    );
}

fVec2 Engine::Screen::Translate(Vec3 point) const {
    return point.z == 0
        ? fVec2((-(point.x)/1),       (point.y/1))
        : fVec2((-(point.x)/point.z), (point.y/point.z));
}

Vec2 Engine::Screen::Project(fVec2 pos, float scale) const {
    Vec2 v(this->Size.x/2, this->Size.y/2);
    // Vec2 p((v.x - (pos.x + (scale/2))), (v.y - (pos.y + (scale/2))));
    return Vec2((v.x - pos.x + (scale/2)), v.y - pos.y + (scale/2));
}
