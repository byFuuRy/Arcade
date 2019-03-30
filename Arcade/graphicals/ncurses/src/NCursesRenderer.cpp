/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** NcursesRenderer
*/

#include <curses.h>

#include "NCursesRenderer.hpp"

#define RGBN(x) x * 1000 / 255

NCursesRenderer::NCursesRenderer()
{
    initscr();
    this->_window = newwin(40, 80, 0, 0);
    nodelay(this->_window, true);
    timeout(0);
    keypad(this->_window, true);
    curs_set(FALSE);
    noecho();
}

NCursesRenderer::~NCursesRenderer()
{
    delwin(this->_window);
    endwin();
}

void NCursesRenderer::drawRectangle(const Rect &rect, const Color &color, bool fill)
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

void NCursesRenderer::drawText(const std::string &text, uint8_t, const Vector &pos, const Color &color)
{
    init_color(COLOR_CYAN, RGBN(color.r), RGBN(color.g), RGBN(color.b));
    init_pair(1, COLOR_BLACK, COLOR_CYAN);
    wattron(this->_window, COLOR_PAIR(1));
    mvwprintw(this->_window, 1,1,"colored text");

    wmove(this->_window, pos.y, pos.x);
    wprintw(this->_window, text.c_str());
}

void NCursesRenderer::display()
{
    wrefresh(this->_window);
    for (; nbWin > 0; --nbWin)
        endwin();
}

void NCursesRenderer::clear()
{
    erase();
    werase(this->_window);
}

void NCursesRenderer::drawSprite(const ASprite *sprite)
{
    this->drawRectangle(sprite->getPosAndSize(), sprite->getFallbackColor(), true);             
}
