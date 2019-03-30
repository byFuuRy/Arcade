/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** NcursesSprite
*/

#ifndef NCURSES_SPRITE_HPP_
#define NCURSES_SPRITE_HPP_

#include "ASprite.hpp"
#include "ATexture.hpp"
#include "Rect.hpp"

class NCursesSprite : public ASprite {
public:
	NCursesSprite(const ATexture *texture, const Rect &spriteSheetRect, const Rect &posAndSize);
	virtual ~NCursesSprite() override = default;

	NCursesSprite(const ASprite &) = delete;
	NCursesSprite &operator=(const ASprite &) = delete;

	virtual void setPosAndSize(const Rect &newPosAndSize) override;
	virtual void setTextureRect(const Rect &newRect) override;
};

#endif /* !NCURSES_SPRITE_HPP_ */