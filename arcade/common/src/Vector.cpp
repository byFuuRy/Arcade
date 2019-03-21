/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Vector
*/

#include "../include/Vector.hpp"

Vector::Vector(double x, double y) noexcept
{
    this->x = x;
    this->y = y;
}

Vector::Vector(const Vector& v) noexcept
{
    this->x = v.x;
    this->y = v.y;
}