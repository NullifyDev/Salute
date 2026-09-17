#ifndef SIZE_HPP
#define SIZE_HPP
#pragma once

#include <variant>

#include "clamp.hpp"
#include "percentage.hpp"
#include "vector.hpp"

struct Clamp;
struct Percentage;
struct Vec2;
struct fVec2;

typedef std::variant<Vec2, fVec2, Percentage, Clamp> Size;
// std::variant<Vec2, Percentage, Clamp> Size;

#endif