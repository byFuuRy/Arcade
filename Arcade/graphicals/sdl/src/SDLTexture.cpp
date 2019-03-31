/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SDLTexture
*/

#include "SDLTexture.hpp"
#include "SDLRenderer.hpp"

SDLTexture::SDLTexture(const void *buffer, const size_t& len)
	: ATexture(buffer, len)
{
    _texture = IMG_LoadPNG_RW(SDL_RWFromConstMem(buffer, len));
}
