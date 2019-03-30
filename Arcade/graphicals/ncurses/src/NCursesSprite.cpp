/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** NcursesSprite
*/

#include "NCursesSprite.hpp"

NCursesSprite::NCursesSprite(const ATexture *texture, const Rect &spriteSheetRect, const Rect &posAndSize)
    : ASprite(texture, spriteSheetRect, posAndSize)
{}

void NCursesSprite::setPosAndSize(const Rect &newPosAndSize)
{
    this->_posAndSize = newPosAndSize;
}

void NCursesSprite::setTextureRect(const Rect &newRect)
{
    this->_spriteSheetRect = newRect;
}