#include "text.hpp"
#include "header.hpp"

#include <variant>

// #include "engine/screen.hpp"
#include "terminal.hpp"

void Text::print(std::shared_ptr<Terminal> screen, const Element *element)
{
    i16 x = 0, y = 0;
    u16 w = 0, h = 0;

    element->prepare(&x, &y, &w, &h);
    screen->Draw(this, x, y, w, h);
}
