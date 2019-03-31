/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** NibblerGame
*/

#ifndef NIBBLERGAME_HPP_
#define NIBBLERGAME_HPP_

#include <vector>

#include "IGame.hpp"
#include "Vector.hpp"

class NibblerGame : public IGame {
public:
	enum Direction {
		UP,
		DOWN,
		LEFT,
		RIGHT,
		NONE
	};
	
	NibblerGame();

	void init(IGraphicLib *);
	void tick(IGraphicLib *, double deltaTime);   // Logic / Physics
	void render(IGraphicLib *);                   // Draw stuff
	void reloadResources(IGraphicLib *);          // Graphic lib changed
	bool isCloseRequested() const noexcept;

private:
	struct Snake {
		Vector _pos;
		
		Snake(const Vector&);
	};
	void move();

	double _time;
	double _speed;
	double _size;
	Direction _direction;
	std::vector<Snake> _snake;
};

extern "C"
{
	IGame *getGameInstance()
	{
		return new NibblerGame();
	}
}

#endif /* !NIBBLERGAME_HPP_ */
