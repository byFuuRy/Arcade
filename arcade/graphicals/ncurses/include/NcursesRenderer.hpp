/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** NcursesRenderer
*/

#pragma once

#include <curses.h>
#include <ncurses.h>
#include <stdexcept>
#include "../../../core/include/IRenderer.hpp"

class NcursesRenderer : public IRenderer {
	public:
		NcursesRenderer();
		~NcursesRenderer();

	    void drawRectangle(const Rect &rect, const Color &color, bool fill = true);
	    void drawLine(const Vector &start, const Vector &end);
	    void drawTexture(const std::string &imagePath, const Vector &pos);
	    void drawText(const std::string &text, uint8_t fontSize, const Vector &pos);

	    void display();
	    void clear();

	protected:
	private:
};
