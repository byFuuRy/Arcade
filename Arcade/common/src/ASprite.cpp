/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** ASprite
*/

#include "ASprite.hpp"

ASprite::ASprite(const ATexture *texture, const Rect &spriteSheetRect, const Rect &posAndSize)
	: _texture(texture), _spriteSheetRect(spriteSheetRect), _posAndSize(posAndSize)
{}

const ATexture *ASprite::getTexture() const noexcept
{
	return this->_texture;
}

const Rect &ASprite::getSpriteSheetRect() const
{
	return this->_spriteSheetRect;
}

const Rect &ASprite::getPosAndSize() const
{
	return this->_posAndSize;
}

const Color &ASprite::getFallbackColor() const
{
	return this->_fallbackColor;
}

void ASprite::setFallbackColor(const Color &color) noexcept
{
	this->_fallbackColor = color;
}
