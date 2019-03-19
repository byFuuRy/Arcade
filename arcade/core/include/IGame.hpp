/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include "IRenderer.hpp"

class IGame {
public:
	virtual ~IGame() = default;

	virtual bool tick() = 0;   // Logic / Physics
	virtual bool render(IRenderer *) = 0; // Draw stuff
	virtual bool isCloseRequested() const noexcept = 0;
};

#endif /* !IGAME_HPP_ */