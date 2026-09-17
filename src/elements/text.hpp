#ifndef TEXT_HPP
#define TEXT_HPP
#pragma once

// #include "../types/size.hpp"
#include "../types/rgb.hpp"

#include <memory>
#include <string>

struct Element;
// namespace Engine {
// 	struct Screen;
// }
struct Terminal;

struct Text // : public Element
{
public:

	Text(RGB background, RGB foreground, std::string text) : Fg(foreground), Bg(background), Content(text) // : Element(location, size, ElementType::Text)
	{}

    // void print(void);

	RGB Fg, Bg;
	std::string Content;

	void print(std::shared_ptr<Terminal> screen, const Element * element);
};
#endif