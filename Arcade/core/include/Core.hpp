/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <string>
#include <vector>

#include "IGraphicLib.hpp"
#include "IGame.hpp"

class Core {
public:
	Core(const std::string &lib_name);
	~Core();
	
	void mainLoop();

private:
    IGraphicLib *getGraphicInstance(const std::string &libPath);
	IGame *getGameInstance(const std::string &libPath);
	void addGraphicLib(const std::string &lib_name);
	void addGameLib();
	void nextGraphicLib();
	void nextGameLib();
	IGraphicLib *getGraphicObject() const;
	IGame *getGameObject() const;
	
	struct Lib {
		std::string _currentPath;
		std::vector<std::string> _listLib;
		void *_currentLib;
		void *_currentObject;
	};
	
	Lib _graphic;
	Lib _game;
	double _deltaTime = 0;
	std::string _error;
};

#endif /* !CORE_HPP_ */
