/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SDLGraphicLib
*/

#include "SDLGraphicLib.hpp"

uint8_t SDLGraphicLib::getGameKeyState() const noexcept
{
    return this->_gameKey;
}

uint8_t SDLGraphicLib::getCoreKeyState() const noexcept
{
    return this->_coreKey;
}

void SDLGraphicLib::pollEvents()
{
    SDL_Event event;

    this->_gameKey = 0;
    this->_coreKey = 0;
    this->_close = false;
    while(SDL_PollEvent(&event) > 0) {
        if (event.type == SDL_QUIT) {
            _close = true;
            continue;
        } else if (event.type != SDL_KEYDOWN)
            continue;
        switch (event.key.keysym.sym) {
            case SDLK_UP: this->_gameKey |= UP; break;
            case SDLK_DOWN: this->_gameKey |= DOWN; break;
            case SDLK_LEFT: this->_gameKey |= LEFT; break;
            case SDLK_RIGHT: this->_gameKey |= RIGHT; break;
            case SDLK_x: this->_gameKey |= PRIMARY; break;
            case SDLK_c: this->_gameKey |= SECONDARY; break;
            case SDLK_b: this->_gameKey |= START; break;
            case SDLK_n: this->_gameKey |= SELECT; break;

            case SDLK_F1: this->_coreKey |= PREV_GRAPHICAL_LIB; break;
            case SDLK_F2: this->_coreKey |= NEXT_GRAPHICAL_LIB; break;
            case SDLK_F3: this->_coreKey |= PREV_GAME_LIB; break;
            case SDLK_F4: this->_coreKey |= NEXT_GAME_LIB; break;
            case SDLK_F5: this->_coreKey |= RESTART_GAME; break;
            case 27: this->_coreKey |= BACK_TO_MENU; break;
            case SDLK_F9: this->_coreKey |= EXIT; break;
            default: break;
        }
    }
}

IRenderer &SDLGraphicLib::getRenderer() noexcept
{
    return this->_renderer;
}

bool SDLGraphicLib::isCloseRequested() const noexcept
{
    return _close;
}

ATexture *SDLGraphicLib::createTexture(const void *buffer, const size_t &len)
{
    return new SDLTexture(buffer, len);
}

ASprite *SDLGraphicLib::createSprite(const ATexture *texture, const Rect &spriteSheetRect, const Rect &posAndSize)
{
    return new SDLSprite(texture, spriteSheetRect, posAndSize);
}