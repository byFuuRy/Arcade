/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** NcursesSprite
*/

#include "NcursesSprite.hpp"

    
NcursesSprite::NcursesSprite(const NcursesSprite &s)
{

}

NcursesSprite &NcursesSprite::operator=(const NcursesSprite &)
{

}

void NcursesSprite::setPosAndSize(const Rect &newPosAndSize)
{
    _posAndSize = newPosAndSize;
}

void NcursesSprite::setTextureRect(const Rect &newRect)
{
    _spriteSheetRect = newRect;
}