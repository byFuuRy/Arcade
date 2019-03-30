/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** ITexture
*/

#ifndef ITEXTURE_HPP_
#define ITEXTURE_HPP_

#include <string>

#include "Color.hpp"

class ITexture {
public:
	ITexture(const std::string &path, const Color &fallbackColor);
	ITexture(const void *memory, const Color &fallbackColor);
	virtual ~ITexture() = default;

	virtual void render() = 0;
};

#endif /* !ITEXTURE_HPP_ */
