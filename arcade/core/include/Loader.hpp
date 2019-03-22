/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Loader
*/

#ifndef LOADER_HPP_
#define LOADER_HPP_

#include <string>
#include <memory>

#include "IGame.hpp"
#include "IGraphicLib.hpp"

class Loader {
public:
    Loader(const std::string &lib_name);
    ~Loader();

    std::unique_ptr<IGame> getGameInstance();
    std::unique_ptr<IGraphicLib> getGraphicLibInstance();

private:
    void *_library;
};

#endif /* !LOADER_HPP_ */
