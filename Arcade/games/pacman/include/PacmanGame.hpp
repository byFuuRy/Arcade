/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** PacmanGame
*/

#ifndef PACMANGAME_HPP_
#define PACMANGAME_HPP_

#include <unordered_map>
#include <deque>
#include <utility>

#include "IGame.hpp"
#include "IGraphicLib.hpp"
#include "Color.hpp"

struct Position {
    Position(int _x, int _y) { x = _x; y = _y; };
    int x;
    int y;
};

struct Ghost {
    struct Position _pos;
    IGraphicLib::GameKey _direction = IGraphicLib::GameKey::SELECT;
    std::deque<std::string> *_map;

    Ghost(int, int, std::deque<std::string> *);

    void move();
    IGraphicLib::GameKey newDir();
};

class PacmanGame : public IGame {
public:

    PacmanGame();
    ~PacmanGame();

    static bool isWall(char c);
    void init(IGraphicLib*);
    void tick(IGraphicLib*, double deltaTime);
    void render(IGraphicLib*);
    void reloadResources(IGraphicLib*);
    bool isCloseRequested() const noexcept;
    bool isGameFinished() const noexcept;
    size_t getScore() const noexcept;

private:
    friend class Ghost;
    double _time = 0;
    Color tileColor(char c);
    size_t _score = 0;
    bool _isGameFinished = false;
    int lives = 4;
    double _speed = 1;
    IGraphicLib::GameKey _direction = IGraphicLib::GameKey::SELECT;
    struct Position _pos = {14, 17};
    void move(uint8_t) noexcept;
    static double getElapsedTime(double t = -1);
    std::unordered_map<short, Ghost*> _ghosts;
    std::deque<std::string> _map;
};

extern "C" {
IGame* getGameInstance()
{
    return new PacmanGame();
}
}

#endif /* !PACMANGAME_HPP_ */
