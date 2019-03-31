/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SDLSprite
*/

#include "SDLSprite.hpp"
#include "SDLRenderer.hpp"

SDLSprite::SDLSprite(const ATexture *texture, const Rect &spriteSheetRect, const Rect &posAndSize)
    : ASprite(texture, spriteSheetRect, posAndSize)
{
    const SDLTexture *sdlTexture = nullptr;

    _rect.h = spriteSheetRect.size.y;
    _rect.w = spriteSheetRect.size.x;
    _rect.x = spriteSheetRect.pos.x;
    _rect.y = spriteSheetRect.pos.y;
    _pos.h = posAndSize.size.y;
    _pos.w = posAndSize.size.x;
    _pos.x = posAndSize.pos.x;
    _pos.y = posAndSize.pos.y;
    sdlTexture = reinterpret_cast<const SDLTexture *>(texture);
    this->_sprite = SDL_CreateTextureFromSurface(SDLRenderer::_renderer, sdlTexture->_texture);
}

void SDLSprite::setPosAndSize(const Rect &newPosAndSize)
{
    this->_posAndSize = newPosAndSize;
}

void SDLSprite::setTextureRect(const Rect &newRect)
{
    this->_spriteSheetRect = newRect;
}