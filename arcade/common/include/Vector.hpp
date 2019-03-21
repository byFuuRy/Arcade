/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Vector
*/

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

struct Vector {
	double x;
	double y;
	
	Vector(const Vector& v) noexcept = default;
	Vector(double x, double y) noexcept;
    Vector(const Vector& v) noexcept;
	~Vector() = default;

	Vector &operator+=(const Vector &vec) noexcept;
	Vector &operator+=(const double &val) noexcept;
	Vector &operator-=(const Vector &vec) noexcept;
	Vector &operator-=(const double &val) noexcept;
	Vector &operator*=(const Vector &vec) noexcept;
	Vector &operator*=(const double &val) noexcept;
	Vector &operator/=(const Vector &vec) noexcept;
	Vector &operator/=(const double &val) noexcept;
	Vector operator+(const Vector &vec) const noexcept;
	Vector operator+(const double &val) const noexcept;
	Vector operator-(const Vector &vec) const noexcept;
	Vector operator-(const double &val) const noexcept;
	Vector operator*(const Vector &vec) const noexcept;
	Vector operator*(const double &val) const noexcept;
	Vector operator/(const Vector &vec) const noexcept;
	Vector operator/(const double &val) const noexcept;
	Vector &operator=(const Vector &vec) noexcept;
	Vector &operator=(const double &val) noexcept;
	bool operator==(const Vector &vec) const noexcept;
	bool operator!=(const Vector &vec) const noexcept;
};

#endif /* !VECTOR_HPP_ */
