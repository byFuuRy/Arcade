/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Rect
*/

#ifndef RECT_HPP_
#define RECT_HPP_

#include "Vector.hpp"


struct Rect {
	Vector pos;
	Vector size;

	Rect(const Vector &pos, const Vector &size) noexcept;
	Rect(double x, double y, double w, double h) noexcept;
	~Rect() = default;
};

#endif /* !RECT_HPP_ */
