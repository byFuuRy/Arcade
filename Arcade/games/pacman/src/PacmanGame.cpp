/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** PacmanGame
*/

#include <iostream>
#include <cmath>
#include<iostream>
#include<time.h>
#include<stdlib.h>

#include "PacmanGame.hpp"

PacmanGame::PacmanGame()
{
    _map.push_back("+------------+------------+");
	_map.push_back("|............|............|");
	_map.push_back("|.+--+.+---+.|.+---+.+--+.|");
	_map.push_back("|@|  |.|   |.|.|   |.|  |@|");
	_map.push_back("|.+--+.+---+.+.+---+.+--+.|");
	_map.push_back("|.........................|");
	_map.push_back("|.+--+.++.+-----+.++.+--+.|");
	_map.push_back("|.+--+.||.+--+--+.||.+--+.|");
	_map.push_back("|......||....|....||......|");
	_map.push_back("+----+.|+--+ | +--+|.+----+");
	_map.push_back("     |.|+--+ + +--+|.|     ");
	_map.push_back("     |.||         ||.|     ");
	_map.push_back("     |.|| +_____+ ||.|     ");
	_map.push_back("-----+.++ |G   G| ++.+-----");
	_map.push_back("      .   |     |   .      ");
	_map.push_back("-----+.++ |G   G| ++.+-----");
	_map.push_back("     |.|| +-----+ ||.|     ");
	_map.push_back("     |.||         ||.|     ");
	_map.push_back("     |.|| +-----+ ||.|     ");
	_map.push_back("+----+.++ +--+--+ ++.+----+");
	_map.push_back("|............|............|");
	_map.push_back("|.+--+.+---+.|.+---+.+--+.|");
	_map.push_back("|.+-+|.+---+.+.+---+.|+-+.|");
	_map.push_back("|@..||...............||..@|");
	_map.push_back("+-+.||.++.+-----+.++.||.+-+");
	_map.push_back("+-+.++.||.+--+--+.||.++.+-+");
	_map.push_back("|......||....|....||......|");
	_map.push_back("|.+----++--+.|.+--++----+.|");
	_map.push_back("|.+--------+.+.+--------+.|");
	_map.push_back("|.........................|");
    _map.push_back("+-------------------------+");
}

PacmanGame::~PacmanGame()
{
    for (auto g : _ghosts)
        delete g.second;
}

void PacmanGame::init(IGraphicLib *)
{
    srand(time(NULL));
    _ghosts.insert({0, new Ghost(11, 13, &_map)});
    _ghosts.insert({1, new Ghost(11, 15, &_map)});
    _ghosts.insert({2, new Ghost(15, 13, &_map)});
    _ghosts.insert({3, new Ghost(15, 15, &_map)});
}

double PacmanGame::getElapsedTime(double t)
{
    static double time = 0;

    if (t != -1)
        time += t;
    return time;
}

bool PacmanGame::isWall(char c)
{
    if (getElapsedTime() < 10 && c == '_')
        return false;
    return (c == '+' || c == '-' || c == '|');
}

void PacmanGame::move(uint8_t dir) noexcept
{
    switch (dir) {
        case IGraphicLib::UP:
            if (_pos.y <= 0 || isWall(_map[_pos.y - 1][_pos.x]))
                _direction = IGraphicLib::PRIMARY;
            else
                _pos.y -= 1;
            break;
        case IGraphicLib::DOWN:
            if (_pos.y + 1 >= (int)_map.size() || isWall(_map[_pos.y + 1][_pos.x]))
                _direction = IGraphicLib::PRIMARY;
            else
                _pos.y += 1;
            break;
        case IGraphicLib::RIGHT:
            if (_map[_pos.y][_pos.x + 1] == '\0' || isWall(_map[_pos.y][_pos.x + 1]))
                _direction = IGraphicLib::PRIMARY;
            else
                _pos.x += 1;
            break;
        case IGraphicLib::LEFT:
            if (isWall(_map[_pos.y][_pos.x - 1]))
                _direction = IGraphicLib::PRIMARY;
            else if (_pos.x <= 0)
                if (_pos.y != 14)
                    _direction = IGraphicLib::PRIMARY;
                else
                    _pos.x = 26;
            else
                _pos.x -= 1;
            break;
    }
}

void PacmanGame::tick(IGraphicLib *lib, double deltaTime)
{
    uint8_t key = lib->getGameKeyState();

    _time += deltaTime;
	_direction = (key & IGraphicLib::UP) ? IGraphicLib::UP : _direction;
	_direction = (key & IGraphicLib::DOWN) ? IGraphicLib::DOWN : _direction;
	_direction = (key & IGraphicLib::LEFT) ? IGraphicLib::LEFT : _direction;
	_direction = (key & IGraphicLib::RIGHT) ? IGraphicLib::RIGHT : _direction;
    _time += deltaTime;
    if (_map[_pos.y][_pos.x] == '.')
        _map[_pos.y][_pos.x] = ' ';
    if (getElapsedTime() < 10)
        getElapsedTime(deltaTime);
    if (_time >= _speed && !isGameFinished()) {
        move(_direction);
        for (auto ghost : _ghosts) {
            ghost.second->move();
            if (ghost.second->_pos.x == _pos.x && ghost.second->_pos.y == _pos.y)
                this->_isGameFinished = true;
        }
		_time -= _speed;
	}
}

Color PacmanGame::tileColor(char tile)
{
    switch (tile) {
    case '+':
        return {0, 0, 255, 255};
    case '-':
        return {0, 0, 255, 255};
    case '|':
        return {0, 0, 255, 255};
    case '.':
        return {255, 255, 0, 255};
    case '@':
        return {255, 0, 0, 255};
    default:
        return {1, 1, 1, 0};
    }
}

void PacmanGame::render(IGraphicLib *lib)
{
    IRenderer &renderer = lib->getRenderer();

    renderer.clear();
    for (int i = 0; i < (int)_map.size(); i++) {
        for (int j = 0; _map[i][j]; j++)
            if (_map[i][j] != ' ')
                renderer.drawRectangle(
                    {j * 0.02, i * 0.02, 1 * 0.02, 1 * 0.02},
                    tileColor(_map[i][j])
                );
    }
    for (auto ghost : _ghosts) {
        renderer.drawRectangle(
            {ghost.second->_pos.x * 0.02, ghost.second->_pos.y * 0.02, 1 * 0.02, 1 * 0.02}, 
            {0, 255, 0, 255}
        );
    }
    renderer.drawRectangle(
        {_pos.x * 0.02, _pos.y * 0.02, 1 * 0.02, 1 * 0.02}, 
        {255, 0, 255, 255}
    );
	renderer.display();
}

void PacmanGame::reloadResources(IGraphicLib *)
{
}

bool PacmanGame::isCloseRequested() const noexcept
{
	return false;
}

bool PacmanGame::isGameFinished() const noexcept
{
	return this->_isGameFinished;
}

size_t PacmanGame::getScore() const noexcept
{
	return this->_score;
}

void Ghost::move()
{
    switch (_direction) {
        case IGraphicLib::UP:
            if (_pos.y <= 0 || PacmanGame::isWall((*_map)[_pos.y - 1][_pos.x]))
                _direction = newDir();
            else
                _pos.y -= 1;
            break;
        case IGraphicLib::DOWN:
            if (_pos.y + 1 >= (int)(*_map).size() || PacmanGame::isWall((*_map)[_pos.y + 1][_pos.x]))
                _direction = newDir();
            else
                _pos.y += 1;
            break;
        case IGraphicLib::RIGHT:
            if ((*_map)[_pos.y][_pos.x + 1] == '\0' || PacmanGame::isWall((*_map)[_pos.y][_pos.x + 1]))
                _direction = newDir();
            else
                _pos.x += 1;
            break;
        case IGraphicLib::LEFT:
            if (PacmanGame::isWall((*_map)[_pos.y][_pos.x - 1]))
                _direction = newDir();
            else if (_pos.x <= 0)
                if (_pos.y != 14)
                    _direction = newDir();
                else
                    _pos.x = 26;
            else
                _pos.x -= 1;
            break;
        default:
            _direction = newDir();
            break;
    }
}
Ghost::Ghost(int _x, int _y, std::deque<std::string> *map) : _pos(_x, _y)
{
    _map = map;
}

IGraphicLib::GameKey Ghost::newDir()
{
    return static_cast<IGraphicLib::GameKey>(1 << rand() % 4);
}
