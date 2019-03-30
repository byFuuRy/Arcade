/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** NCursesGraphicLib
*/

#include "NcursesGraphicLib.hpp"
#include "NcursesRenderer.hpp"

uint8_t NcursesGraphicLib::getGameKeyState() const noexcept
{
    int key = getch();

    if (_keymap.find(key) != _keymap.end())
        return this->_keymap.at(key);
    return 0;
}

uint8_t NcursesGraphicLib::getCoreKeyState() const noexcept
{
    if (_coremap.find(_key) != _coremap.end())
        return this->_coremap.at(_key);
    return 0;
}

void sendGameKeyInput(IGraphicLib::GameKey input) noexcept
{
}

void sendCoreKeyInput(IGraphicLib::CoreKey input) noexcept
{
}

void NcursesGraphicLib::pollEvents()
{
    _key = getch();
}

IRenderer& NcursesGraphicLib::getRenderer() noexcept
{
    return *this->_renderer;
}

bool NcursesGraphicLib::isCloseRequested() const noexcept
{
    return false;
}

NcursesGraphicLib::NcursesGraphicLib()
{
    this->_renderer = new NcursesRenderer();
    this->_keymap = {
        { KEY_DOWN, IGraphicLib::GameKey::DOWN },
        { KEY_UP, IGraphicLib::GameKey::UP },
        { KEY_LEFT, IGraphicLib::GameKey::LEFT },
        { KEY_RIGHT, IGraphicLib::GameKey::RIGHT },
        { 'x', IGraphicLib::GameKey::PRIMARY },
        { 'c', IGraphicLib::GameKey::SECONDARY },
        { KEY_ENTER, IGraphicLib::GameKey::START },
        { ' ', IGraphicLib::GameKey::SELECT }
    };
    this->_coremap = {
        { 'a', IGraphicLib::PREV_GRAPHICAL_LIB },
        { '\t', IGraphicLib::NEXT_GRAPHICAL_LIB },
        { 'g', IGraphicLib::PREV_GAME_LIB },
        { 'h', IGraphicLib::NEXT_GAME_LIB },
        { 'r', IGraphicLib::RESTART_GAME },
        { 'm', IGraphicLib::BACK_TO_MENU },
        { 'q', IGraphicLib::EXIT }
    };
}

NcursesGraphicLib::~NcursesGraphicLib()
{
}

ATexture *createTexture(const void *buffer, const size_t &len)
{
}

ASprite *createSprite(const ATexture *texture, const Rect &spriteSheetRect, const Rect &posAndSize)
{
}

