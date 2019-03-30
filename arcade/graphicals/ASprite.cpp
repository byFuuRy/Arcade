/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** ASprite
*/

#include "ASprite.hpp"
    
const ATexture *ASprite::getTexture() const noexcept
{
    return _texture;
}

const Rect &ASprite::getSpriteSheetRect() const
{
    return _spriteSheetRect;
}

const Rect &ASprite::getPosAndSize() const
{
    return _posAndSize;
}

const Color &ASprite::getFallbackColor() const
{
    return _fallbackColor;
}

void ASprite::setFallbackColor(const Color &color) noexcept
{
    _fallbackColor = color;
}
