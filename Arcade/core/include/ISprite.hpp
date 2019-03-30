/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** ISprite
*/

#ifndef ISPRITE_HPP_
#define ISPRITE_HPP_

#include "ITexture.hpp"
#include "Rect.hpp"

class ISprite {
public:
	// A rectangle on position 0, 0 and of size 0, 0 loads the whole texture.
	ISprite(const ITexture &text, const Rect &rect = Rect(0, 0, 0, 0)) noexcept;
	virtual ~ISprite() = default;

	virtual void moveRect(const Rect &newRect) noexcept;
};

#endif /* !ISPRITE_HPP_ */
