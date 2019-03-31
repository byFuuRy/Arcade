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
	void tick(IGraphicLib *, double deltaTime);
	void render(IGraphicLib *);
	void reloadResources(IGraphicLib *);
	bool isCloseRequested() const noexcept;
	bool isGameFinished() const noexcept;
	size_t getScore() const noexcept;

private:
	struct Snake {
		Vector _pos;
		
		Snake(const Vector&);
	};
	void move() noexcept;
	void popFood() noexcept;
	void isFoodAte() noexcept;
	void generateMap() noexcept;
	void displaySnake(IGraphicLib *graphic) const noexcept;
	void displayMap(IGraphicLib *graphic) const noexcept;
	void displayGameOver(IGraphicLib *graphic) noexcept;
	void isGameOver() noexcept;

	size_t _score;
	size_t _bestScore;
	bool _isGameFinished;
	double _time;
	double _speed;
	double _size;
	Vector _food;
	Direction _direction;
	std::vector<Snake> _snake;
	std::vector<Vector> _obstacles;
};

extern "C"
{
	IGame *getGameInstance()
	{
		return new NibblerGame();
	}
}

#endif /* !NIBBLERGAME_HPP_ */
