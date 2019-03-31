/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Rect
*/

#include "Rect.hpp"

Rect::Rect(const Vector &pos, const Vector &size) noexcept 
: pos(pos), size(size)
{}

Rect::Rect(double x, double y, double w, double h) noexcept 
: pos(x, y), size(w, h)
{}

bool Rect::operator==(const Rect &rhs) const noexcept
{
	return (this->pos.x == rhs.pos.x && this->pos.y == rhs.pos.y &&
			this->size.x == rhs.size.x && this->size.y == rhs.pos.y);
}

bool Rect::operator!=(const Rect &rhs) const noexcept
{
	return (this->pos.x != rhs.pos.x || this->pos.y != rhs.pos.y ||
			this->size.x != rhs.size.x || this->size.y != rhs.pos.y);
}