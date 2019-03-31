/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Core
*/

#include <dlfcn.h>
#include <cstdlib>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <filesystem>
#include <regex>

#include "Core.hpp"

Core::~Core()
{
	if (this->_graphic._currentLib != nullptr)
		dlclose(this->_graphic._currentLib);
	if (this->_game._currentLib != nullptr)
		dlclose(this->_game._currentLib);
}

Core::Core(const std::string &libName)
	: _deltaTime(0)
{
	const auto libPath = realpath(libName.c_str(), nullptr);

	if (libPath == nullptr) {
		this->_error = libName + ": " + "File does not exist.";
		throw std::runtime_error(this->_error);
	}
	this->addGraphicLib(libPath);
	this->addGameLib();
	this->_graphic._currentObject = this->getGraphicInstance(this->_graphic._listLib.front());
	this->_game._currentObject = this->getGameInstance(this->_game._listLib.front());
}

void Core::addGraphicLib(const std::string &libName)
{
	std::regex r("lib_arcade_(.+)\\.so$");
	std::smatch match;

	this->_graphic._listLib.push_back(libName);
	for (auto &entry : std::filesystem::directory_iterator(realpath("./lib", nullptr))) {
		std::string path = entry.path().c_str();
		if (std::find(this->_graphic._listLib.begin(), this->_graphic._listLib.end(), path) == this->_graphic._listLib.end()
			&& std::regex_search(path, match, r))
        	this->_graphic._listLib.push_back(entry.path().c_str());
	}
}

void Core::addGameLib()
{
	std::regex r("lib_arcade_(.+)\\.so$");
	std::smatch match;

	for (auto &entry : std::filesystem::directory_iterator(realpath("./games", nullptr))) {
		std::string path = entry.path().c_str();
		if (std::regex_search(path, match, r))
        	this->_game._listLib.push_back(entry.path().c_str());
	}
}

IGraphicLib *Core::getGraphicInstance(const std::string &libPath)
{
	using getInstance = IGraphicLib *();
	getInstance *f;
	
	this->_graphic._currentLib = dlopen(libPath.c_str(), RTLD_LAZY);
	if (this->_graphic._currentLib == nullptr)
		throw std::runtime_error(dlerror());
	f = reinterpret_cast<getInstance*>(dlsym(this->_graphic._currentLib, "getGraphicalInstance"));
	if (f == nullptr)
		throw std::runtime_error(dlerror());
	this->_graphic._currentPath = libPath;
	return f();
}

IGame *Core::getGameInstance(const std::string &libPath)
{
	using getInstance = IGame *();
	getInstance *f;

	this->_game._currentLib = dlopen(libPath.c_str(), RTLD_LAZY);
	if (this->_game._currentLib == nullptr)
		throw std::runtime_error(dlerror());
	f = reinterpret_cast<getInstance*>(dlsym(this->_game._currentLib, "getGameInstance"));
	if (f == nullptr)
		throw std::runtime_error(dlerror());
	this->_game._currentPath = libPath;
	return f();
}

IGraphicLib *Core::getGraphicObject() const
{
	return static_cast<IGraphicLib*>(this->_graphic._currentObject);
}

IGame *Core::getGameObject() const
{
	return static_cast<IGame*>(this->_game._currentObject);
}

void Core::nextGraphicLib()
{
	if (this->_graphic._listLib.size() == 1)
		return;
	if (this->_graphic._currentLib != nullptr) {
		delete this->getGraphicObject();
		dlclose(this->_graphic._currentLib);
	}
	auto it = std::find(this->_graphic._listLib.begin(), this->_graphic._listLib.end(), this->_graphic._currentPath);
	if (it + 1 == this->_graphic._listLib.end())
		this->_graphic._currentObject = this->getGraphicInstance(this->_graphic._listLib.front());
	else
		this->_graphic._currentObject = this->getGraphicInstance(*(it + 1));
	if (this->_graphic._currentObject == nullptr) {
		this->_error = *(it + 1) + ": " + "Can't load the graphic library.";
		throw std::runtime_error(this->_error);
	}
	this->getGameObject()->reloadResources(this->getGraphicObject());
}

void Core::prevGraphicLib()
{
	if (this->_graphic._listLib.size() == 1)
		return;
	if (this->_graphic._currentLib != nullptr) {
		delete this->getGraphicObject();
		dlclose(this->_graphic._currentLib);
	}
	auto it = std::find(this->_graphic._listLib.begin(), this->_graphic._listLib.end(), this->_graphic._currentPath);
	if (it == this->_graphic._listLib.begin())
		this->_graphic._currentObject = this->getGraphicInstance(this->_graphic._listLib.back());
	else
		this->_graphic._currentObject = this->getGraphicInstance(*(it - 1));
	if (this->_graphic._currentObject == nullptr) {
		this->_error = *(it + 1) + ": " + "Can't load the graphic library.";
		throw std::runtime_error(this->_error);
	}
	this->getGameObject()->reloadResources(this->getGraphicObject());
}

void Core::nextGameLib()
{
	if (this->_game._listLib.size() == 1)
		return;
	if (this->_game._currentLib != nullptr) {
		delete this->getGameObject();
		dlclose(this->_game._currentLib);
	}
	auto it = std::find(this->_game._listLib.begin(), this->_game._listLib.end(), this->_game._currentPath);
	if (it + 1 == this->_game._listLib.end())
		this->_game._currentObject = this->getGameInstance(this->_game._listLib.front());
	else
		this->_game._currentObject = this->getGameInstance(*(it + 1));
	if (this->_game._currentObject == nullptr) {
		this->_error = *(it + 1) + ": " + "Can't load the game.";
		throw std::runtime_error(this->_error);
	}
	this->getGameObject()->init(this->getGraphicObject());
}

void Core::prevGameLib()
{
	if (this->_game._listLib.size() == 1)
		return;
	if (this->_game._currentLib != nullptr) {
		delete this->getGameObject();
		dlclose(this->_game._currentLib);
	}
	auto it = std::find(this->_game._listLib.begin(), this->_game._listLib.end(), this->_game._currentPath);
	if (it == this->_game._listLib.begin())
		this->_game._currentObject = this->getGameInstance(this->_game._listLib.back());
	else
		this->_game._currentObject = this->getGameInstance(*(it - 1));
	if (this->_game._currentObject == nullptr) {
		this->_error = *(it + 1) + ": " + "Can't load the game.";
		throw std::runtime_error(this->_error);
	}
}

void Core::close()
{
	if (this->_game._currentLib != nullptr) {
		delete this->getGameObject();
		dlclose(this->_game._currentLib);
	}
	if (this->_graphic._currentLib != nullptr) {
		delete this->getGraphicObject();
		dlclose(this->_graphic._currentLib);
	}
}

void Core::restartGame()
{
	if (this->_game._currentLib != nullptr) {
		delete this->getGameObject();
		dlclose(this->_game._currentLib);
	}
	this->_game._currentObject = this->getGameInstance(this->_game._currentPath);
	this->getGameObject()->init(this->getGraphicObject());
}

bool Core::performAction()
{
	this->getGraphicObject()->pollEvents();
	switch (this->getGraphicObject()->getCoreKeyState()) {
		case IGraphicLib::NEXT_GRAPHICAL_LIB: this->nextGraphicLib(); break;
		case IGraphicLib::PREV_GRAPHICAL_LIB: this->prevGraphicLib(); break;
		case IGraphicLib::NEXT_GAME_LIB: this->nextGameLib(); break;
		case IGraphicLib::PREV_GAME_LIB: this->prevGameLib(); break;
		case IGraphicLib::RESTART_GAME: this->restartGame(); break;
		case IGraphicLib::BACK_TO_MENU: this->backToMenu(); break;
		case IGraphicLib::EXIT: this->close(); return false;
		default: break;
	}
	return true;
}

void Core::backToMenu()
{
	this->restartGame();
	this->_menu._active = true;
}

void Core::Menu::setNames(Core &core)
{
	std::regex r("lib_arcade_(.+)\\.so$");
	std::smatch match;

	for (const auto &lib : core._graphic._listLib) {
		if (std::regex_search(lib, match, r))
			this->_graphicName.push_back(std::make_pair(match[1].str(), lib));
	}
	for (const auto &lib : core._game._listLib) {
		if (std::regex_search(lib, match, r))
			this->_gameName.push_back(std::make_pair(match[1].str(), lib));
	}
}

Color Core::Menu::isFocused(const std::string &item)
{
	return (this->_focused == item) ? Color(0, 0, 160) : Color(255, 255, 255);
}

std::string &Core::Menu::setFocused(int8_t iadd)
{
	ssize_t graphicNameLen = static_cast<ssize_t>(this->_graphicName.size());
	ssize_t gameNameLen = static_cast<ssize_t>(this->_gameName.size());
	
	for (ssize_t i = 0; i < graphicNameLen; i++)
		if (this->_graphicName[i].first == this->_focused) {
			return (i - iadd < 0 || i - iadd >= graphicNameLen) ? ((iadd < 0) ?
				this->_graphicName.front().first : this->_graphicName.back().first) : this->_graphicName[i - iadd].first;
		}
	for (ssize_t i = 0; i < gameNameLen; i++)
		if (this->_gameName[i].first == this->_focused)
			return (i - iadd < 0 || i - iadd >= gameNameLen) ? ((iadd < 0) ?
				this->_gameName.front().first : this->_gameName.back().first) : this->_gameName[i - iadd].first;
	return this->_graphicName.front().first;
}

void Core::Menu::printNames(Core &core)
{
	this->_focused = (core.getGraphicObject()->getGameKeyState() & IGraphicLib::RIGHT) ? this->_gameName.front().first : this->_focused;
	this->_focused = (core.getGraphicObject()->getGameKeyState() & IGraphicLib::LEFT) ? this->_graphicName.front().first : this->_focused;
	this->_focused = (core.getGraphicObject()->getGameKeyState() & IGraphicLib::UP) ? this->setFocused(1) : this->_focused;
	this->_focused = (core.getGraphicObject()->getGameKeyState() & IGraphicLib::DOWN) ? this->setFocused(-1) : this->_focused;	
	
	core.getGraphicObject()->getRenderer().drawText("Graphicals:", 30, Vector(0.2, 0.3), Color(255, 255, 255));
	for (size_t i = 0; i < this->_graphicName.size(); i++)
		core.getGraphicObject()->getRenderer().drawText(this->_graphicName[i].first, 28, Vector(0.2, 0.38 + (static_cast<double>(i) / 20)),
			this->isFocused(this->_graphicName[i].first));
	core.getGraphicObject()->getRenderer().drawText("Games:", 30, Vector(0.7, 0.3), Color(255, 255, 255));
	for (size_t i = 0; i < this->_gameName.size(); i++)
		core.getGraphicObject()->getRenderer().drawText(this->_gameName[i].first, 28, Vector(0.7, 0.38 + (static_cast<double>(i) / 20)),
			this->isFocused(this->_gameName[i].first));
}

bool Core::Menu::setNewPath(Core &core)
{
	for (const auto &pair : this->_graphicName)
		if (pair.first == this->_focused) {
			delete core.getGraphicObject();
			dlclose(core._graphic._currentLib);
			core._graphic._currentObject = core.getGraphicInstance(pair.second);
		}
	for (const auto &pair : this->_gameName)
		if (pair.first == this->_focused) {
			delete core.getGameObject();
			dlclose(core._game._currentLib);
			core._game._currentObject = core.getGameInstance(pair.second);
		}
	this->_focused.erase();
	return false;
}

void Core::Menu::showMenu(Core &core)
{
	if (this->_graphicName.empty())
		this->setNames(core);
	this->_active = (core.getGraphicObject()->getGameKeyState() & IGraphicLib::START) ? (this->_focused.size() != 0) ?
		this->setNewPath(core) : false : true;
	core.getGraphicObject()->getRenderer().clear();
	this->printNames(core);
	core.getGraphicObject()->getRenderer().drawText("Main Menu", 50, Vector(0.41, 0), Color(160, 0, 0));
	core.getGraphicObject()->getRenderer().display();
}

void Core::mainLoop()
{	
	this->getGameObject()->init(getGraphicObject());
	while (!this->getGraphicObject()->isCloseRequested() && !getGameObject()->isCloseRequested()) {
		auto start = std::chrono::system_clock::now();
		if (!this->performAction())
			return;
		if (this->_menu._active)
			this->_menu.showMenu(*this);
		else {
			getGameObject()->tick(getGraphicObject(), this->_deltaTime);
			getGameObject()->render(getGraphicObject());
			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double> elapsed = end - start;
			this->_deltaTime = elapsed.count();
		}
	}
}