#ifndef VECTOR3_HPP
#define VECTOR3_HPP
#pragma once

#include "HAL/Platform.h"

struct Vec3
{
    Vec3() = default;
    ~Vec3() {
        this->x = 0;
        this->y = 0;
        this->ptrx = nullptr;
        this->ptry = nullptr;
        this->equalizeAspectRatio = false;
    };

    Vec3(const Vec3 &&vec,     const bool equalizeAspectRatio = false) : x(equalizeAspectRatio ? vec.x*2 : vec.x), y(vec.y), z(vec.z), ptrx(nullptr), ptry(nullptr), ptrz(nullptr), equalizeAspectRatio(equalizeAspectRatio) {}
    Vec3(u16 x, u16 y,  u16 z, const bool equalizeAspectRatio = false) : x(equalizeAspectRatio ?     x*2 :     x), y(y),     z(z),     ptrx(nullptr), ptry(nullptr), ptrz(nullptr), equalizeAspectRatio(equalizeAspectRatio) {}

    u16  getx() const { return this->ptrx == nullptr ? this->x : *this->ptrx; }
    u16  gety() const { return this->ptry == nullptr ? this->y : *this->ptry; }
    u16  getz() const { return this->ptrz == nullptr ? this->y : *this->ptrz; }

    u16 x = 0, y = 0, z = 0, *ptrx, *ptry, *ptrz;
    bool equalizeAspectRatio = false;
};

struct fVec3
{
    fVec3() = default;
    fVec3(float x, float y) : x(x), y(y)
    {
        this->x = x;
        this->y = y;
    }
    ~fVec3() {
        this->x = 0;
        this->y = 0;
    }

    auto ToVec3()   const -> Vec3 { return Vec3(static_cast<u16>(x), static_cast<u16>(y), static_cast<u16>(z)); }
    auto ToString() const -> std::string {
        return std::string("").append(std::to_string(this->x).c_str())
                                    .append(":")
                                    .append(std::to_string(this->y).c_str());
    }

    float x = 0, y = 0, z = 0;
};
#endif
