/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** ASprite
*/

#ifndef ASPRITE_HPP_
#define ASPRITE_HPP_

#include "ATexture.hpp"
#include "Rect.hpp"
#include "Color.hpp"

class ASprite {
public:
	ASprite(const ATexture *texture, const Rect &spriteSheetRect, const Rect &posAndSize);
	virtual ~ASprite() = default;

	ASprite(const ASprite &) = delete;
	ASprite &operator=(const ASprite &) = delete;

	virtual void setPosAndSize(const Rect &newPosAndSize) = 0;
	virtual void setTextureRect(const Rect &newRect) = 0;

	virtual const ATexture *getTexture() const noexcept final;
	virtual const Rect &getSpriteSheetRect() const final;
	virtual const Rect &getPosAndSize() const final;
	virtual const Color &getFallbackColor() const final;

	virtual void setFallbackColor(const Color &color) noexcept final;
protected:
	const ATexture *_texture;
	Rect _spriteSheetRect;
	Rect _posAndSize;

	Color _fallbackColor{255, 255, 255, 255};
};

#endif /* !ASPRITE_HPP_ */