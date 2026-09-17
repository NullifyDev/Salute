#ifndef VECTOR_HPP
#define VECTOR_HPP
#pragma once

#include "HAL/Platform.h"

#include <string>

struct Vec2
{
	Vec2() = default;
	~Vec2() {
		this->x = 0;
		this->y = 0;
		this->ptrx = nullptr;
		this->ptry = nullptr;
		this->equalizeAspectRatio = false;
	};

	Vec2(u16 x, u16 y,     const bool equalizeAspectRatio = false) : x(equalizeAspectRatio ?     (x*2)+1 :     x), y(y),     ptrx(nullptr), ptry(nullptr), equalizeAspectRatio(equalizeAspectRatio) {}
	Vec2(const Vec2 &vec,  const bool equalizeAspectRatio = false) : x(equalizeAspectRatio ? vec.x*2 : vec.x), y(vec.y), ptrx(nullptr), ptry(nullptr), equalizeAspectRatio(equalizeAspectRatio) {}
	// Vec2(u16 x, u16 *y,    const bool equalizeAspectRatio = false) : x(equalizeAspectRatio ? x*2 : x),         y(0),     ptrx(nullptr), ptry(y),       equalizeAspectRatio(equalizeAspectRatio) {}
	// Vec2(u16 *x, u16 y,    const bool equalizeAspectRatio = false) : x(0),                                     y(y),     ptrx(x),       ptry(nullptr), equalizeAspectRatio(equalizeAspectRatio) {
	// 	*this->ptrx = equalizeAspectRatio ? (*x)*2 : *x;
	// }
	Vec2(u16 *x, u16 *y,   const bool equalizeAspectRatio = false) : x(0),                                     y(0),     ptrx(x),       ptry(y),       equalizeAspectRatio(equalizeAspectRatio) {
	   *this->ptrx = equalizeAspectRatio ? *this->ptrx*2 : *this->ptrx;
	}

	u16 getx() const { return this->ptrx == nullptr ? this->x : *this->ptrx; }
	u16 gety() const { return this->ptry == nullptr ? this->y : *this->ptry; }
	Vec2 get() const { return Vec2(getx(), gety()); }

	u16 x = 1, y = 1, *ptrx, *ptry;
	bool equalizeAspectRatio = false;
};

struct fVec2
{
	fVec2() = default;
	fVec2(float x, float y, bool equalizeAspectRatio = false) : x(equalizeAspectRatio == true ? (x*2.0f)+1.0f : x ), y(y), equalizeAspectRatio(equalizeAspectRatio) {}

	~fVec2() {
		this->x = 0;
		this->y = 0;
	}

	auto ToVec2()   const -> Vec2 { return Vec2(static_cast<u16>(x), static_cast<u16>(y)); }
	auto ToString() const -> std::string {
		return std::string("").append(std::to_string(this->x).c_str())
									.append(":")
									.append(std::to_string(this->y).c_str());
	}

	float x = 0, y = 0;
	bool equalizeAspectRatio = false;
};

#endif
