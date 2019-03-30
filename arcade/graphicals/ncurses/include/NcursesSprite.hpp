/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** NcursesSprite
*/

#pragma once

#include "ASprite.hpp"

class NcursesSprite : public ASprite {
	public:
    	NcursesSprite(const ATexture *texture, const Rect &spriteSheetRect, const Rect &posAndSize);
    	virtual ~NcursesSprite() override = default;
    
    	NcursesSprite(const ASprite &) = delete;
    	NcursesSprite &operator=(const ASprite &) override = delete;
    
    	virtual void setPosAndSize(const Rect &newPosAndSize) override;
    	virtual void setTextureRect(const Rect &newRect) override;
	protected:
	private:
};
