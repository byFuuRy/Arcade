/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Loader
*/

#include <dlfcn.h>
#include <string>
#include <iostream>
#include <cstdlib>

#include "Loader.hpp"

Loader::Loader(const std::string &lib_name)
{
    this->_library = dlopen(realpath(lib_name.c_str(), NULL), RTLD_LAZY);
    if (this->_library == NULL) {
        throw;
    }
}

Loader::~Loader()
{
    if (this->_library != NULL)
        dlclose(this->_library);
}

std::unique_ptr<IGraphicLib> Loader::getGraphicLibInstance()
{
    typedef IGraphicLib *(*func_ptr)();
    func_ptr func;

    if (this->_library == NULL) {
        return NULL;
    }
    func = (func_ptr)dlsym(this->_library, "getInstance");
    if (func == NULL) {
        return NULL;
    }
    return std::unique_ptr<IGraphicLib>(func());
}

std::unique_ptr<IGame> Loader::getGameInstance()
{
    typedef IGame *(*func_ptr)();
    func_ptr func;
    
    if (this->_library == NULL)
        return NULL;
    func = (func_ptr)dlsym(this->_library, "getInstance");
    if (func == NULL)
        return NULL;
    return std::unique_ptr<IGame>(func());
}