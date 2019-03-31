/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** NcursesRenderer
*/

#include <curses.h>

#include "NCursesRenderer.hpp"

#define RGBN(x) (x * 1000 / 255)

NCursesRenderer::NCursesRenderer()
{
    if (initscr() == nullptr)
        throw std::runtime_error("Can't initialize nCurses sreen.");
    noecho();
    nodelay(this->_window, true);
    curs_set(0);
    keypad(stdscr, true);
    timeout(0);
    start_color();
    this->_window = newwin(this->_h, this->_w, (LINES / 2) - (this->_h / 2), (COLS / 2) - (this->_w / 2));
    if (this->_window == nullptr)
        throw std::runtime_error("Can't create nCurses window.");
}

NCursesRenderer::~NCursesRenderer()
{
    delwin(this->_window);
    endwin();
}

void NCursesRenderer::_colorInitialization(const Color &color, bool fill)
{
    init_color(++this->_colorReference, static_cast<short>(RGBN(color.r)),
        static_cast<short>(RGBN(color.g)), static_cast<short>(RGBN(color.b)));
    init_pair(this->_colorReference, this->_colorReference, static_cast<short>(fill ? this->_colorReference : COLOR_BLACK));
}

void NCursesRenderer::drawRectangle(const Rect &rect, const Color &color, bool fill)
{
    this->_colorInitialization(color, fill);
    wattron(this->_window, COLOR_PAIR(this->_colorReference));
    for (size_t y = 0; y < rect.size.y * this->_h; y++) {
        for (size_t x = 0; x < rect.size.x * this->_w; x++) {
            mvwaddch(this->_window, rect.pos.y * this->_h + static_cast<double>(y) / this->_h,
                rect.pos.x * this->_w + static_cast<double>(x) / this->_w, 0);
        }
    }
    wattroff(this->_window, COLOR_PAIR(this->_colorReference));
}

void NCursesRenderer::drawText(const std::string &text, uint8_t, const Vector &pos, const Color &color)
{
    this->_colorInitialization(color);
    wattron(this->_window, COLOR_PAIR(this->_colorReference));
    mvwaddstr(this->_window, static_cast<int>(pos.y * this->_h), static_cast<int>(pos.x * this->_w), text.c_str());
    wattroff(this->_window, COLOR_PAIR(this->_colorReference));
}

void NCursesRenderer::drawSprite(const ASprite *sprite)
{
    this->drawRectangle(sprite->getPosAndSize(), sprite->getFallbackColor(), true);             
}

void NCursesRenderer::display()
{
    wnoutrefresh(this->_window);
    doupdate();
}

void NCursesRenderer::clear()
{
    werase(this->_window);
    mvwin(this->_window, (LINES / 2) - (this->_h / 2), (COLS / 2) - (this->_w / 2));
    wresize(this->_window, this->_h, this->_w);
    this->_colorReference = 0;
}

