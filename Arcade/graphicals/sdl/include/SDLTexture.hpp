/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SDLTexture
*/

#ifndef NCURSES_TEXTURE_HPP_
#define NCURSES_TEXTURE_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "ATexture.hpp"

class SDLTexture : public ATexture {
public:
	SDLTexture(const void *buffer, const size_t &len);

	SDLTexture(const SDLTexture&) = default;
	SDLTexture& operator=(const SDLTexture&) = default;

    SDL_Surface *_texture;
};

#endif /* !NCURSES_TEXTURE_HPP_ */