/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SFMLSprite
*/

#include "SFMLSprite.hpp"

SFMLSprite::SFMLSprite(const ATexture *texture, const Rect &spriteSheetRect, const Rect &posAndSize)
    : ASprite(texture, spriteSheetRect, posAndSize)
{
    sf::IntRect rect(spriteSheetRect.pos.x, spriteSheetRect.pos.y, spriteSheetRect.size.x, spriteSheetRect.size.y);
    sf::Vector2f pos(posAndSize.pos.x, posAndSize.pos.y);
    sf::Vector2f size(posAndSize.size.x, posAndSize.size.y);
    
    _sprite.setTexture(reinterpret_cast<const SFMLTexture *>(texture)->_texture);
    _sprite.setTextureRect(rect);
    _sprite.setPosition(pos);
    _sprite.setScale(size);
}

void SFMLSprite::setPosAndSize(const Rect &newPosAndSize)
{
    this->_posAndSize = newPosAndSize;
}

void SFMLSprite::setTextureRect(const Rect &newRect)
{
    this->_spriteSheetRect = newRect;
}