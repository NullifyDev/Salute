#ifndef HEADER_HPP
#define HEADER_HPP
#pragma once

#include <string>
#include <variant>
#include <vector>

#include "text.hpp"
#include "square.hpp"
// #include "Engine/screen.hpp"

#include "types/size.hpp"
#include "types/rgb.hpp"
#include "HAL/Platform.h"


namespace Engine {
	class Screen;
}

typedef std::variant<Square, Text> UIElement;

struct Element
{
	Size location, size;
	UIElement element;
	std::vector<Element> children;


	Element(const Size& location, const Size& size, const RGB& background, const RGB& foreground) : location(location), size(size), element(Square(background, foreground)) {}
	Element(const Size& location, const Size& size, const RGB& background, const RGB& foreground, const char *content) : location(location), size(size), element(Text(background, foreground, content)) {}

	Element *const GetElement();
	void prepare(i16 *x, i16 *y, u16 *w, u16 *h) const;
	void print(std::shared_ptr<Terminal> screen) const;
	void to_str() const;
	void AddChild(Element e);

private:
	// Element *parent;
};
#endif