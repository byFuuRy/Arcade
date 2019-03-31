/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Main
*/

#include <iostream>

#include "Core.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Usage: ./arcade lib_arcade_{GRAPHIC_LIB}.so" << std::endl;
        return 84;
    }
    try {
        Core core(av[1]);
        core.mainLoop();
    } catch (const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
        return 84;
    }
    return 0;
}