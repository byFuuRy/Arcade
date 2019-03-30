/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SFMLRenderer
*/

#include <SFML>

#include "../include/SFMLRenderer.hpp"

#define RGBN(x) x * 1000 / 255

SFMLRenderer::SFMLRenderer()
{
}

SFMLRenderer::~SFMLRenderer()
{
}

void SFMLRenderer::drawRectangle(const Rect &rect, const Color &color, bool fill)
{
    WINDOW *win = newwin(rect.size.y + 1, rect.size.x + 1, rect.pos.y, rect.pos.x);

    init_color(COLOR_CYAN, RGBN(color.r), RGBN(color.g), RGBN(color.b));
    init_pair(1, COLOR_CYAN, COLOR_CYAN);
    if (fill) {
        wbkgd(win, COLOR_PAIR(1));
        box(win, 0, 0);
    } else {
        wattron(win, COLOR_PAIR(1));
        box(win, 0, 0);
        wattroff(win, COLOR_PAIR(1));
    }
    touchwin(win);
    wrefresh(win);
    ++nbWin;
}

void SFMLRenderer::drawLine(const Vector &start, const Vector &end, const Color &color)
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

void SFMLRenderer::drawTexture(const std::string &imagePath, const Vector &pos)
{
}

void SFMLRenderer::drawText(const std::string &text, uint8_t fontSize, const Vector &pos, const Color &color)
{
    init_color(COLOR_CYAN, RGBN(color.r), RGBN(color.g), RGBN(color.b));
    init_pair(1, COLOR_BLACK, COLOR_CYAN);
    attron(COLOR_PAIR(1));
    mvprintw(1,1,"colored text");

    move(pos.y, pos.x);
    printw(text.c_str());
}

void SFMLRenderer::display()
{
    refresh();
    for (; nbWin > 0; --nbWin)
        endwin();
}

void SFMLRenderer::clear()
{
    erase();
}
