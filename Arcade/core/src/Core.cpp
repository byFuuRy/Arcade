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
{
	const auto libPath = realpath(libName.c_str(), nullptr);

	if (libPath == nullptr) {
		this->_error = libName + ": " + "File does not exist.";
		throw std::runtime_error(this->_error);
	}
	addGraphicLib(libPath);
	addGameLib();
	this->_graphic._currentObject = getGraphicInstance(this->_graphic._listLib.front());
	this->_game._currentObject = getGameInstance(this->_game._listLib.front());
}

void Core::addGraphicLib(const std::string &libName)
{
	std::regex r("lib_arcade_(.+)\\.so$");
	std::smatch match;

	this->_graphic._listLib.push_back(libName);
	for (auto &entry : std::filesystem::directory_iterator(realpath("./lib", nullptr))) {
		std::string path = entry.path().c_str();
		if (std::find(this->_graphic._listLib.begin(), this->_graphic._listLib.end(), libName) == this->_graphic._listLib.end()
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

void Core::nextGraphicLib()
{
	if (this->_graphic._listLib.size() == 1)
		return;
	if (this->_graphic._currentLib != nullptr)
		dlclose(this->_graphic._currentLib);
	auto it = std::find(this->_graphic._listLib.begin(), this->_graphic._listLib.end(), this->_graphic._currentPath);
	if (it + 1 == this->_graphic._listLib.end())
		this->_graphic._currentObject = this->getGraphicInstance(this->_graphic._listLib.front());
	else
		this->_graphic._currentObject = getGraphicInstance(*(it + 1));
	if (this->_graphic._currentObject == nullptr) {
		this->_error = *(it + 1) + ": " + "Can't load the graphic library.";
		throw std::runtime_error(this->_error);
	}
}

void Core::nextGameLib()
{
	if (this->_game._listLib.size() == 1)
		return;
	if (this->_game._currentLib != nullptr)
		dlclose(this->_game._currentLib);
	auto it = std::find(this->_game._listLib.begin(), this->_game._listLib.end(), this->_game._currentPath);
	if (it + 1 == this->_game._listLib.end())
		this->_game._currentObject = this->getGameInstance(this->_game._listLib.front());
	else
		this->_game._currentObject = getGameInstance(*(it + 1));
	if (this->_game._currentObject == nullptr) {
		this->_error = *(it + 1) + ": " + "Can't load the game.";
		throw std::runtime_error(this->_error);
	}
}

IGraphicLib *Core::getGraphicObject() const
{
	return static_cast<IGraphicLib*>(this->_graphic._currentObject);
}

IGame *Core::getGameObject() const
{
	return static_cast<IGame*>(this->_game._currentObject);
}

void Core::mainLoop()
{	
	getGameObject()->init(getGraphicObject());
	while (!getGraphicObject()->isCloseRequested() && !getGameObject()->isCloseRequested()) {
		auto start = std::chrono::system_clock::now();
		getGraphicObject()->pollEvents();
		getGameObject()->tick(getGraphicObject(), this->_deltaTime);
		getGameObject()->render(getGraphicObject());
		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed = end - start;
		this->_deltaTime = elapsed.count();
	}
}