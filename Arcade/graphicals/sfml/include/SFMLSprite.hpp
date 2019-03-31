/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SFMLSprite
*/

#ifndef NCURSES_SPRITE_HPP_
#define NCURSES_SPRITE_HPP_

#include <SFML/Graphics/Sprite.hpp>

#include "ASprite.hpp"
#include "Rect.hpp"
#include "SFMLTexture.hpp"

class SFMLSprite : public ASprite {
public:
	SFMLSprite(const ATexture *texture, const Rect &spriteSheetRect, const Rect &posAndSize);
	virtual ~SFMLSprite() override = default;

	SFMLSprite(const ASprite &) = delete;
	SFMLSprite &operator=(const ASprite &) = delete;

	virtual void setPosAndSize(const Rect &newPosAndSize) override;
	virtual void setTextureRect(const Rect &newRect) override;

    sf::Sprite _sprite;
};

#endif /* !NCURSES_SPRITE_HPP_ */