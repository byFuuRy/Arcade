/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Rect
*/

#ifndef RECT_HPP_
#define RECT_HPP_

#include "Vector.hpp"

struct Rect final {
	Vector pos;
	Vector size;

	Rect() noexcept;
	Rect(const Vector &pos, const Vector &size) noexcept;
	Rect(double x, double y, double w, double h) noexcept;
	~Rect() = default;

	bool operator==(const Rect &rhs) const noexcept;
	bool operator!=(const Rect &rhs) const noexcept;
	Rect &operator=(const Rect &rhs) noexcept;
};

#endif /* !RECT_HPP_ */
