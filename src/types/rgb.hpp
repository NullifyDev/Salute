#ifndef RGB_H
#define RGB_H
#pragma once

#include <stdint.h>

typedef struct RGB 
{
	uint8_t r, g, b;
	RGB(uint8_t r, uint8_t g, uint8_t b): r(r), g(g), b(b) {}
} RGB;
#endif
