/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Color
*/

#ifndef COLOR_HPP_
#define COLOR_HPP_

#include <cstdint>

struct Color {
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) noexcept;
	~Color() = default;

	uint32_t getValue() const noexcept;
};

#endif /* !COLOR_HPP_ */
