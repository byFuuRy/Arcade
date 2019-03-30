/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** NCursesGraphicLib
*/

#include "SFMLGraphicLib.hpp"
#include "SFMLRenderer.hpp"

uint8_t SFMLGraphicLib::getGameKeyState() const noexcept
{
}

uint8_t SFMLGraphicLib::getCoreKeyState() const noexcept
{
}

void sendGameKeyInput(IGraphicLib::GameKey input) noexcept
{
}

void sendCoreKeyInput(IGraphicLib::CoreKey input) noexcept
{
}

void SFMLGraphicLib::pollEvents()
{
}

IRenderer &SFMLGraphicLib::getRenderer() noexcept
{
    return new SFMLRenderer();
}

bool SFMLGraphicLib::isCloseRequested() const noexcept
{
}
