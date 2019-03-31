#include "Core.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    try {
        Core core(av[1]);
        core.mainLoop();
    } catch (const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}