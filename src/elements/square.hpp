#ifndef SQUARE_HPP
#define SQUARE_HPP
#pragma once

#include <memory>
#include "../types/rgb.hpp"


// namespace Engine {
// 	class Screen;
// }


struct Element;
struct Terminal;

struct Square // : public Element
{
public:
	RGB  Bg = RGB(0, 0, 0),
		 Fg = RGB(255, 255, 255);

	Square(RGB background, RGB foreground) : Bg(background), Fg(foreground) {} // : Element(location, size, ElementType::Square) {}

	void print(std::shared_ptr<Terminal> screen, const Element *element);

	// void print(Square s);
};
#endif