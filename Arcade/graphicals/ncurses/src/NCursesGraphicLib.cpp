/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** NCursesGraphicLib
*/

#include "NCursesGraphicLib.hpp"

uint8_t NCursesGraphicLib::getGameKeyState() const noexcept
{
    return this->_gameKey;
}

uint8_t NCursesGraphicLib::getCoreKeyState() const noexcept
{
    return this->_coreKey;
}

void NCursesGraphicLib::pollEvents()
{
    auto inputKey = getch();
    
    this->_gameKey = 0;
    this->_coreKey = 0;
    switch (inputKey)
    {
        case KEY_UP: this->_gameKey |= UP; break;
        case KEY_DOWN: this->_gameKey |= DOWN; break;
        case KEY_LEFT: this->_gameKey |= LEFT; break;
        case KEY_RIGHT: this->_gameKey |= RIGHT; break;
        case 'x': this->_gameKey |= PRIMARY; break;
        case 'c': this->_gameKey |= SECONDARY; break;
        case 'b': this->_gameKey |= START; break;
        case 'n': this->_gameKey |= SELECT; break;

        case KEY_F(1): this->_coreKey |= PREV_GRAPHICAL_LIB; break;
        case KEY_F(2): this->_coreKey |= NEXT_GRAPHICAL_LIB; break;
        case KEY_F(3): this->_coreKey |= PREV_GAME_LIB; break;
        case KEY_F(4): this->_coreKey |= NEXT_GAME_LIB; break;
        case KEY_F(5): this->_coreKey |= RESTART_GAME; break;
        case 27: this->_coreKey |= BACK_TO_MENU; break;
        case KEY_F(9): this->_coreKey |= EXIT; break;
    }
}

IRenderer &NCursesGraphicLib::getRenderer() noexcept
{
    return this->_renderer;
}

bool NCursesGraphicLib::isCloseRequested() const noexcept
{
    return false;
}

ATexture *NCursesGraphicLib::createTexture(const void *buffer, const size_t &len)
{
    return new NCursesTexture(buffer, len);
}

ASprite *NCursesGraphicLib::createSprite(const ATexture *texture, const Rect &spriteSheetRect, const Rect &posAndSize)
{
    return new NCursesSprite(texture, spriteSheetRect, posAndSize);
}