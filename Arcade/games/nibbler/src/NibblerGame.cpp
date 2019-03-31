/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** NibblerGame
*/

#include <iostream>
#include <cmath>

#include "NibblerGame.hpp"

NibblerGame::Snake::Snake(const Vector &vec)
	: _pos(vec)
{}

NibblerGame::NibblerGame()
	: _score(0), _bestScore(0), _isGameFinished(false), _time(0), _speed(0.1), _size(1.0 / 40), _food(0, 0), _direction(UP)
{}

void NibblerGame::init(IGraphicLib *)
{
	srand(static_cast<unsigned int>(time(0)));
	this->_snake.push_back(Snake(Vector(20, 20)));
	this->_snake.push_back(Snake(Vector(20, 20 + this->_snake.size())));
	this->_snake.push_back(Snake(Vector(20, 20 + this->_snake.size())));
	this->_snake.push_back(Snake(Vector(20, 20 + this->_snake.size())));
	this->_snake.push_back(Snake(Vector(20, 20 + this->_snake.size())));
	this->generateMap();
	this->popFood();
}

void NibblerGame::tick(IGraphicLib *graphic, double deltaTime)
{
	this->_direction = (graphic->getGameKeyState() & IGraphicLib::UP) ? this->UP : this->_direction;
	this->_direction = (graphic->getGameKeyState() & IGraphicLib::DOWN) ? this->DOWN : this->_direction;
	this->_direction = (graphic->getGameKeyState() & IGraphicLib::LEFT) ? this->LEFT : this->_direction;
	this->_direction = (graphic->getGameKeyState() & IGraphicLib::RIGHT) ? this->RIGHT : this->_direction;
	this->_time += deltaTime;
	if (this->_time >= this->_speed && !this->isGameFinished()) {
		this->move();
		this->isFoodAte();
		this->isGameOver();
		this->_time -= this->_speed;
	}
}

void NibblerGame::render(IGraphicLib *graphic)
{
	graphic->getRenderer().clear();
	graphic->getRenderer().drawText("Nibbler", 30, Vector(0.38, 0), Color(255, 255, 255));
	graphic->getRenderer().drawText("score:", 24, Vector(0.01, 0), Color(255, 255, 255));
	graphic->getRenderer().drawText(std::to_string(this->_score), 24, Vector(0.12, 0), Color(255, 255, 255));
	graphic->getRenderer().drawText("best score:", 24, Vector(0.70, 0), Color(255, 255, 255));
	graphic->getRenderer().drawText(std::to_string(this->_bestScore), 24, Vector(0.9, 0), Color(255, 255, 255));

	this->displaySnake(graphic);
	graphic->getRenderer().drawRectangle(Rect(Vector(this->_food.x * this->_size, this->_food.y * this->_size),
		Vector(this->_size, this->_size)), Color(247, 174, 75));
	this->displayMap(graphic);
	if (this->isGameFinished())
		this->displayGameOver(graphic);
	graphic->getRenderer().display();
}

void NibblerGame::reloadResources(IGraphicLib *)
{}

bool NibblerGame::isCloseRequested() const noexcept
{
	return false;
}

bool NibblerGame::isGameFinished() const noexcept
{
	return this->_isGameFinished;
}

size_t NibblerGame::getScore() const noexcept
{
	return this->_bestScore;
}

void NibblerGame::move() noexcept
{
	switch (this->_direction) {
		case UP:
			this->_snake.insert(this->_snake.begin(), Vector(this->_snake.front()._pos.x, this->_snake.front()._pos.y - 1));
			this->_snake.pop_back(); break;
		case DOWN:
			this->_snake.insert(this->_snake.begin(), Vector(this->_snake.front()._pos.x, this->_snake.front()._pos.y + 1));
			this->_snake.pop_back(); break;
		case LEFT:
			this->_snake.insert(this->_snake.begin(), Vector(this->_snake.front()._pos.x - 1, this->_snake.front()._pos.y));
			this->_snake.pop_back(); break;
		case RIGHT:
			this->_snake.insert(this->_snake.begin(), Vector(this->_snake.front()._pos.x + 1, this->_snake.front()._pos.y));
			this->_snake.pop_back(); break;
		default: break;
	}
}

void NibblerGame::popFood() noexcept
{
	double randomX = rand()%38 + 2;
	double randomY = rand()%38 + 4;
	
	randomX = randomX > 38 ? 38 : randomX;
	randomY = randomY > 38 ? 38 : randomY;
	for (const auto &obstacle : this->_obstacles) {
		if (randomX == obstacle.x && randomY == obstacle.y)
			this->popFood();
	}
	this->_food.x = randomX > 38 ? 38 : randomX;
	this->_food.y = randomY > 38 ? 38 : randomY;
}

void NibblerGame::isFoodAte() noexcept
{
	if (this->_snake.front()._pos.x == this->_food.x && this->_snake.front()._pos.y == this->_food.y) {
		switch (this->_direction) {
			case UP: this->_snake.insert(this->_snake.begin(), Vector(this->_snake.front()._pos.x, this->_snake.front()._pos.y - 1)); break;
			case DOWN: this->_snake.insert(this->_snake.begin(), Vector(this->_snake.front()._pos.x, this->_snake.front()._pos.y + 1)); break;
			case LEFT: this->_snake.insert(this->_snake.begin(), Vector(this->_snake.front()._pos.x - 1, this->_snake.front()._pos.y)); break;
			case RIGHT: this->_snake.insert(this->_snake.begin(), Vector(this->_snake.front()._pos.x + 1, this->_snake.front()._pos.y)); break;
			default: break;
		}
		this->_score += 1;
		this->_bestScore = this->_bestScore < this->_score ? this->_score : this->_bestScore;
		this->popFood();
	}
}

void NibblerGame::generateMap() noexcept
{
	size_t obstaclesNumber = rand()%20 + 10;
	while (this->_obstacles.size() != obstaclesNumber) {
		double randomX = rand()%37 + 3;
		double randomY = rand()%37 + 5;
		
		randomX = randomX > 37 ? 37 : randomX;
		randomY = randomY > 37 ? 37 : randomY;
		if (randomX != 20 || randomY > 24 || randomY < 10)
			this->_obstacles.push_back(Vector(randomX, randomY));
	}
	for (size_t i = 0; i < 40; i++) {
		if (i >= 2) {
			this->_obstacles.push_back(Vector(39, i));
			this->_obstacles.push_back(Vector(0, i));
		}
		this->_obstacles.push_back(Vector(i, 2));
		this->_obstacles.push_back(Vector(i, 39));
	}
}

void NibblerGame::displaySnake(IGraphicLib *graphic) const noexcept
{
	for (size_t i = 0; i < this->_snake.size(); i++) {
		const auto part = this->_snake[i];
		if (i == 0)
			graphic->getRenderer().drawRectangle(Rect(Vector(part._pos.x * this->_size, part._pos.y * this->_size),
				Vector(this->_size, this->_size)), Color(183, 208, 212));
		else if (i == this->_snake.size() - 1)
			graphic->getRenderer().drawRectangle(Rect(Vector(part._pos.x * this->_size, part._pos.y * this->_size),
				Vector(this->_size, this->_size)), Color(75, 101, 128));
		else
			graphic->getRenderer().drawRectangle(Rect(Vector(part._pos.x * this->_size, part._pos.y * this->_size),
				Vector(this->_size, this->_size)), Color(247, 174, 75));
	}
}

void NibblerGame::displayMap(IGraphicLib *graphic) const noexcept
{
	for (const auto &obstacle : this->_obstacles) {
		graphic->getRenderer().drawRectangle(Rect(Vector(obstacle.x * this->_size, obstacle.y * this->_size),
			Vector(this->_size, this->_size)), Color(90, 156, 161));
	}
}

void NibblerGame::displayGameOver(IGraphicLib *graphic) noexcept
{
	if (graphic->getGameKeyState() & IGraphicLib::PRIMARY) {
		graphic->getRenderer().clear();
		this->_score = 0;
		this->_isGameFinished = false;
		this->_direction = UP;
		this->_snake.clear();
		this->_obstacles.clear();
		this->_time = 0;
		this->init(graphic);
	} else {
		graphic->getRenderer().drawText("Game Over", 30, Vector(0.42, 0.4), Color(255, 0, 0));
		graphic->getRenderer().drawText("Press X to restart.", 25, Vector(0.37, 0.48), Color(255, 255, 255));
		graphic->getRenderer().drawRectangle(Rect(Vector(0, 0),
			Vector(40 * this->_size, 40 * this->_size)), Color(0, 0, 0, 120));
	}
}

void NibblerGame::isGameOver() noexcept
{
	for (const auto &obstacle : this->_obstacles) {
		if (obstacle.x == this->_snake.front()._pos.x && obstacle.y == this->_snake.front()._pos.y)
			this->_isGameFinished = true;
	}
}