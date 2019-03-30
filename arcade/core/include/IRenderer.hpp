/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** IRenderer
*/

#ifndef IRENDERER_HPP_
#define IRENDERER_HPP_

#include <string>

#include "Vector.hpp"
#include "Color.hpp"
#include "Rect.hpp"
#include "ASprite.hpp"

class IRenderer {
public:
	virtual ~IRenderer() = default;

	virtual void drawRectangle(const Rect &rect, const Color &color, bool fill = true) = 0;
	virtual void drawSprite(const ASprite *sprite) = 0;
	virtual void drawText(const std::string &text, uint8_t fontSize, const Vector &pos, const Color &color) = 0;

	virtual void display() = 0;
	virtual void clear() = 0;
};

#endif /* !IRENDERER_HPP_ */
