/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SDLSprite
*/

#ifndef NCURSES_SPRITE_HPP_
#define NCURSES_SPRITE_HPP_

#include "ASprite.hpp"
#include "Rect.hpp"
#include "SDLTexture.hpp"

class SDLSprite : public ASprite {
public:
	SDLSprite(const ATexture *texture, const Rect &spriteSheetRect, const Rect &posAndSize);
	virtual ~SDLSprite() override = default;

	SDLSprite(const ASprite &) = delete;
	SDLSprite &operator=(const ASprite &) = delete;

	virtual void setPosAndSize(const Rect &newPosAndSize) override;
	virtual void setTextureRect(const Rect &newRect) override;

    SDL_Texture *_sprite;
    SDL_Rect _rect;
    SDL_Rect _pos;
};

#endif /* !NCURSES_SPRITE_HPP_ */