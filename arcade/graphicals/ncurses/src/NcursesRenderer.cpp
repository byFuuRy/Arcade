/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** NcursesRenderer
*/

#include <curses.h>

#include "../include/NcursesRenderer.hpp"

#define RGBN(x) x * 1000 / 255

NcursesRenderer::NcursesRenderer()
{
    initscr();
    this->_window = newwin(40, 80, 0, 0);
    nodelay(this->_window, true);
    timeout(0);
    keypad(this->_window, true);
    curs_set(FALSE);
    noecho();
}

NcursesRenderer::~NcursesRenderer()
{
    delwin(this->_window);
    endwin();
}

void NcursesRenderer::drawRectangle(const Rect &rect, const Color &color, bool fill)
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

void NcursesRenderer::drawText(const std::string &text, uint8_t fontSize, const Vector &pos, const Color &color)
{
    init_color(COLOR_CYAN, RGBN(color.r), RGBN(color.g), RGBN(color.b));
    init_pair(1, COLOR_BLACK, COLOR_CYAN);
    wattron(_window, COLOR_PAIR(1));
    mvwprintw(_window, 1,1,"colored text");

    wmove(_window, pos.y, pos.x);
    wprintw(_window, text.c_str());
}

void NcursesRenderer::display()
{
    wrefresh(_window);
    for (; nbWin > 0; --nbWin)
        endwin();
}

void NcursesRenderer::clear()
{
    erase();
    werase(this->_window);
}

void NcursesRenderer::drawSprite(const ASprite *sprite)
{
    this->drawRectangle(sprite->getPosAndSize(), sprite->getFallbackColor(), true);             
}
