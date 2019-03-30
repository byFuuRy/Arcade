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
	void loadGraphic(const std::string &libPath);
	void loadGame(const std::string &libPath);
    IGraphicLib *getGraphicLibInstance() const;
	IGame *getGameInstance() const;
	void addGraphicLib(const std::string &lib_name);
	void addGameLib(const std::string &lib_name);
	void nextGraphicLib();
	void nextGameLib();
	
	struct Lib {
		std::string _currentPath;
		std::vector<std::string> _listLib;
		void *_currentLib;
		void *_currentObject;
	};
	
	Lib _graphic;
	Lib _game;
	std::string _error;
};

#endif /* !CORE_HPP_ */
