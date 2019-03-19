/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** NcursesRenderer
*/

#include <curses.h>

#include "../include/NcursesRenderer.hpp"

NcursesRenderer::NcursesRenderer()
{
}

NcursesRenderer::~NcursesRenderer()
{
}

void NcursesRenderer::drawRectangle(const Rect &rect, const Color &color, bool fill)
{
    WINDOW *win = newwin(rect.size.y, rect.size.x, rect.pos.y, rect.pos.x);

    box(win, '#', '#');
    touchwin(win);
    wrefresh(win);
}

void NcursesRenderer::drawLine(const Vector &start, const Vector &end)
{
    double tilt = 0;
    int counter = 0;

    if (start.y == end.y) {
        if (start.x < end.x)
            mvhline(start.y, start.x, '#', end.x - start.x + 1);
        else
            mvhline(end.y, end.x, '#', start.x - end.x + 1);
        return;
    } else if (start.x == end.x) {
        if (start.y < end.y)
            mvvline(start.y, start.x, '#', end.y - start.y + 1);
        else
            mvvline(end.y, end.x, '#', start.y - end.y + 1);
        return;
    }
    tilt = (end.x - start.x) / (end.y - start.y);
    if (tilt < 0)
        tilt *= -1;
    for (int i = 0; i < end.y; ++i) {
        move(start.y + i, start.x + counter);
        for (int j = 0; j < tilt; ++j, ++counter)
            printw("#");
    }
}

void NcursesRenderer::drawTexture(const std::string &imagePath, const Vector &pos)
{
}

void NcursesRenderer::drawText(const std::string &text, uint8_t fontSize, const Vector &pos)
{
    move(pos.y, pos.x);
    printw(text.c_str());
}

void NcursesRenderer::display()
{
}

void NcursesRenderer::clear()
{
}
