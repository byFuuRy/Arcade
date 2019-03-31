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

    _rect.h = spriteSheetRect.size.y * 800;
    _rect.w = spriteSheetRect.size.x * 800;
    _rect.x = spriteSheetRect.pos.x * 800;
    _rect.y = spriteSheetRect.pos.y * 800;
    _pos.h = posAndSize.size.y * 800;
    _pos.w = posAndSize.size.x * 800;
    _pos.x = posAndSize.pos.x * 800;
    _pos.y = posAndSize.pos.y * 800;
    sdlTexture = reinterpret_cast<const SDLTexture *>(texture);
    this->_sprite = SDL_CreateTextureFromSurface(getRenderer(), sdlTexture->_texture);
}

void SDLSprite::setPosAndSize(const Rect &newPosAndSize)
{
    this->_posAndSize = newPosAndSize;
}

void SDLSprite::setTextureRect(const Rect &newRect)
{
    this->_spriteSheetRect = newRect;
}