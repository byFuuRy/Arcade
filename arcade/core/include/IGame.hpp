/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include "IRenderer.hpp"
#include "IGraphicLib.hpp"

class IGame {
public:
	virtual ~IGame() = default;

	virtual void init(IGraphicLib *) = 0;
	virtual void tick(IGraphicLib *, double deltaTime) = 0;   // Logic / Physics
	virtual void render(IGraphicLib *) = 0;                   // Draw stuff
	virtual void reloadResources(IGraphicLib *) = 0;          // Graphic lib changed
	virtual bool isCloseRequested() const noexcept = 0;
};

#endif /* !IGAME_HPP_ */