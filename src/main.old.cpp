#include "elements/header.hpp"
#include "layers.hpp"

#include "terminal.hpp"
#include "engine/camera.hpp"

int main() {



    Terminal terminal;
    Element(
        v,
        Vec2(1,1, true),
        RGB(0, 190, 80),
        RGB(255, 255, 255)
    ).print(std::make_shared<Engine::Screen>(s));

    return 0;
}