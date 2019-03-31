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
#include <utility>

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
	IGraphicLib *getGraphicObject() const;
	IGame *getGameObject() const;
	
	bool performAction();
	void nextGraphicLib();
	void prevGraphicLib();
	void nextGameLib();
	void prevGameLib();
	void restartGame();
	void backToMenu();
	void close();
	
	struct Lib {
		std::string _currentPath;
		std::vector<std::string> _listLib;
		void *_currentLib;
		void *_currentObject;
	};
	
	struct Menu {
		void setNames(Core &core);
		void showMenu(Core &core);
		void printNames(Core &core);
		Color isFocused(const std::string &item);
		std::string &setFocused(int8_t imul);
		bool setNewPath(Core &core);

		bool _active = false;
		std::vector<std::pair<std::string, std::string>> _graphicName{};
		std::vector<std::pair<std::string, std::string>> _gameName{};
		std::string _focused;
	};

	Lib _graphic;
	Lib _game;
	double _deltaTime;
	std::string _error;
	Menu _menu;
};

#endif /* !CORE_HPP_ */
