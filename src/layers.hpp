#ifndef LAYERS_HPP
#define LAYERS_HPP
#pragma once

// #include "elements/header.hpp"
#include "engine/screen.hpp"

#include <memory>
#include <vector>

struct Layers
{
    auto Add(Element element) -> void;
    auto Add(std::vector<Element> element_items) -> void;
    auto Print(std::weak_ptr<Terminal> terminal) -> void;
    auto to_str() -> void;
private:
    // std::stack<Element> stack;   PLAN: data inheritence (pos, size, etc.)
    std::vector<Element> elements;
};
#endif