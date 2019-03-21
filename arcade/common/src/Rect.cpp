/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Rect
*/

#include "../include/Rect.hpp"

Rect::Rect(const Vector &pos, const Vector &size) noexcept 
: pos(pos), size(size)
{
}

Rect::Rect(double x, double y, double w, double h) noexcept 
: pos(x, y), size(x, y)
{
}