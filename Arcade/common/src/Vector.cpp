/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Vector
*/

#include "Vector.hpp"

Vector::Vector(double x, double y) noexcept
{
    this->x = x;
    this->y = y;
}

Vector &Vector::operator+=(const Vector &vec) noexcept
{
    this->x += vec.x;
    this->y += vec.y;
    return *this;
}

Vector &Vector::operator+=(const double &val) noexcept
{
    this->x += val;
    this->y += val;
    return *this;
}

Vector &Vector::operator-=(const Vector &vec) noexcept
{
    this->x -= vec.x;
    this->y -= vec.y;
    return *this;
}

Vector &Vector::operator-=(const double &val) noexcept
{
    this->x -= val;
    this->y -= val;
    return *this;
}

Vector &Vector::operator*=(const Vector &vec) noexcept
{
    this->x *= vec.x;
    this->y *= vec.y;
    return *this;
}

Vector &Vector::operator*=(const double &val) noexcept
{
    this->x *= val;
    this->y *= val;
    return *this;
}

Vector &Vector::operator/=(const Vector &vec)
{
    this->x /= vec.x;
    this->y /= vec.y;
    return *this;
}

Vector &Vector::operator/=(const double &val)
{
    this->x /= val;
    this->y /= val;
    return *this;
}

Vector Vector::operator+(const Vector &vec) const noexcept
{
    Vector copy(*this);

    return copy += vec;
}

Vector Vector::operator+(const double &val) const noexcept
{
    Vector copy(*this);

    return copy += val;
}

Vector Vector::operator-(const Vector &vec) const noexcept
{
    Vector copy(*this);

    return copy -= vec;
}

Vector Vector::operator-(const double &val) const noexcept
{
    Vector copy(*this);

    return copy -= val;
}

Vector Vector::operator*(const Vector &vec) const noexcept
{
    Vector copy(*this);

    return copy *= vec;
}

Vector Vector::operator*(const double &val) const noexcept
{
    Vector copy(*this);

    return copy *= val;
}

Vector Vector::operator/(const Vector &vec) const
{
    Vector copy(*this);

    return copy /= vec;
}

Vector Vector::operator/(const double &val) const
{
    Vector copy(*this);

    return copy /= val;
}

Vector &Vector::operator=(const Vector &vec) noexcept
{
    this->x = vec.x;
    this->y = vec.y;
    return *this;
}

Vector &Vector::operator=(const double &val) noexcept
{
    this->x = val;
    this->y = val;
    return *this;
}

bool Vector::operator==(const Vector &vec) const noexcept
{
    return (this->x == vec.x && this->y == vec.y);
}

bool Vector::operator!=(const Vector &vec) const noexcept
{
    return (this->x != vec.x || this->y != vec.y);
}