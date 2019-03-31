/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SFMLGraphicLib
*/

#include "SFMLGraphicLib.hpp"

uint8_t SFMLGraphicLib::getGameKeyState() const noexcept
{
    return this->_gameKey;
}

uint8_t SFMLGraphicLib::getCoreKeyState() const noexcept
{
    return this->_coreKey;
}

void SFMLGraphicLib::pollEvents()
{
    sf::Event event;

    this->_gameKey = 0;
    this->_coreKey = 0;
    this->_close = false;
    while(this->_renderer._window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _close = true;
            continue;
        } else if (event.type != sf::Event::KeyPressed)
            continue;
        switch (event.key.code)
        {
            case sf::Keyboard::Up: this->_gameKey |= UP; break;
            case sf::Keyboard::Down: this->_gameKey |= DOWN; break;
            case sf::Keyboard::Left: this->_gameKey |= LEFT; break;
            case sf::Keyboard::Right: this->_gameKey |= RIGHT; break;
            case sf::Keyboard::X: this->_gameKey |= PRIMARY; break;
            case sf::Keyboard::C: this->_gameKey |= SECONDARY; break;
            case sf::Keyboard::B: this->_gameKey |= START; break;
            case sf::Keyboard::N: this->_gameKey |= SELECT; break;

            case sf::Keyboard::F1: this->_coreKey |= PREV_GRAPHICAL_LIB; break;
            case sf::Keyboard::F2: this->_coreKey |= NEXT_GRAPHICAL_LIB; break;
            case sf::Keyboard::F3: this->_coreKey |= PREV_GAME_LIB; break;
            case sf::Keyboard::F4: this->_coreKey |= NEXT_GAME_LIB; break;
            case sf::Keyboard::F5: this->_coreKey |= RESTART_GAME; break;
            case 27: this->_coreKey |= BACK_TO_MENU; break;
            case sf::Keyboard::F9: this->_coreKey |= EXIT; break;
            default: break;
        }
    }
}

IRenderer &SFMLGraphicLib::getRenderer() noexcept
{
    return this->_renderer;
}

bool SFMLGraphicLib::isCloseRequested() const noexcept
{
    return _close;
}

ATexture *SFMLGraphicLib::createTexture(const void *buffer, const size_t &len)
{
    return new SFMLTexture(buffer, len);
}

ASprite *SFMLGraphicLib::createSprite(const ATexture *texture, const Rect &spriteSheetRect, const Rect &posAndSize)
{
    return new SFMLSprite(texture, spriteSheetRect, posAndSize);
}