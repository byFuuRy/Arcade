/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** NibblerGame
*/

#include <iostream>

#include "NibblerGame.hpp"

NibblerGame::Snake::Snake(const Vector &vec)
	: _pos(vec)
{}

void NibblerGame::move(IGraphicLib *graphic)
{
	this->_direction = (graphic->getGameKeyState() & IGraphicLib::UP) ? this->UP : this->_direction;
	this->_direction = (graphic->getGameKeyState() & IGraphicLib::DOWN) ? this->DOWN : this->_direction;
	this->_direction = (graphic->getGameKeyState() & IGraphicLib::LEFT) ? this->LEFT : this->_direction;
	this->_direction = (graphic->getGameKeyState() & IGraphicLib::RIGHT) ? this->RIGHT : this->_direction;
	switch (this->_direction) {
		case UP:
			this->_snake.insert(this->_snake.begin(), Vector(this->_snake.front()._pos.x, this->_snake.front()._pos.y - 1));
			this->_snake.pop_back();
			break;
		case DOWN:
			this->_snake.insert(this->_snake.begin(), Vector(this->_snake.front()._pos.x, this->_snake.front()._pos.y + 1));
			this->_snake.pop_back();
			break;
		case LEFT:
			this->_snake.insert(this->_snake.begin(), Vector(this->_snake.front()._pos.x - 1, this->_snake.front()._pos.y));
			this->_snake.pop_back();
			break;
		case RIGHT:
			this->_snake.insert(this->_snake.begin(), Vector(this->_snake.front()._pos.x + 1, this->_snake.front()._pos.y));
			this->_snake.pop_back();
			break;
		default: break;
	}
}

NibblerGame::NibblerGame()
	: _time(0), _speed(0.1), _size(1.0 / 40), _direction(UP)
{
	this->_snake.push_back(Snake(Vector(20, 20)));
	this->_snake.push_back(Snake(Vector(20, 20 + this->_snake.size())));
	this->_snake.push_back(Snake(Vector(20, 20 + this->_snake.size())));
	this->_snake.push_back(Snake(Vector(20, 20 + this->_snake.size())));
	this->_snake.push_back(Snake(Vector(20, 20 + this->_snake.size())));
}

void NibblerGame::init(IGraphicLib *)
{}

void NibblerGame::tick(IGraphicLib *graphic, double deltaTime)
{
	this->_time += deltaTime;
	if (this->_time >= this->_speed) {
		this->move(graphic);
		this->_time -= this->_speed;
	}
}

void NibblerGame::render(IGraphicLib *graphic)
{
	graphic->getRenderer().clear();
	graphic->getRenderer().drawText("Nibbler", 50, Vector(0.38, 0), Color(255, 255, 255));
	graphic->getRenderer().drawText("score", 25, Vector(0.01, 0), Color(255, 255, 255));
	graphic->getRenderer().drawText("best score", 25, Vector(0.82, 0), Color(255, 255, 255));
	for (size_t i = 0; i < this->_snake.size(); i++) {
		const auto part = this->_snake[i];
		if (i == 0)
			graphic->getRenderer().drawRectangle(Rect(Vector(part._pos.x * this->_size, part._pos.y * this->_size), Vector(this->_size, this->_size)), Color(255, 0, 0));
		else if (i == this->_snake.size() - 1)
			graphic->getRenderer().drawRectangle(Rect(Vector(part._pos.x * this->_size, part._pos.y * this->_size), Vector(this->_size, this->_size)), Color(0, 0, 255));
		else
			graphic->getRenderer().drawRectangle(Rect(Vector(part._pos.x * this->_size, part._pos.y * this->_size), Vector(this->_size, this->_size)), Color(0, 255, 0));
	}
	graphic->getRenderer().display();
}

void NibblerGame::reloadResources(IGraphicLib *)
{

}

bool NibblerGame::isCloseRequested() const noexcept
{
	return false;
}