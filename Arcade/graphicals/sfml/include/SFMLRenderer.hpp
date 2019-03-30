/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SFMLRenderer
*/

#pragma once

#include <stdexcept>
#include "../../../core/include/IRenderer.hpp"

class SFMLRenderer : public IRenderer {
	public:
		SFMLRenderer();
		~SFMLRenderer();

	    void drawRectangle(const Rect &rect, const Color &color, bool fill = true);
	    void drawLine(const Vector &start, const Vector &end, const Color &color);
	    void drawTexture(const std::string &imagePath, const Vector &pos);
	    void drawText(const std::string &text, uint8_t fontSize, const Vector &pos, const Color &color);

	    void display();
	    void clear();

	protected:
        short nbWin = 0;
	private:
};
