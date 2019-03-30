/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SFMLGraphicLib
*/

#pragma once

#include "IGraphicLib.hpp"
#include "IGame.hpp"

class SFMLGraphicLib : public IGraphicLib 
{
    public:
		SFMLGraphicLib() = default;
		~SFMLGraphicLib() = default;
        uint8_t SFMLGraphicLib::getCoreKeyState() const noexcept;
        uint8_t SFMLGraphicLib::getGameKeyState() const noexcept;
        void sendGameKeyInput(GameKey input) noexcept;
        void sendCoreKeyInput(CoreKey input) noexcept;
        void SFMLGraphicLib::pollEvents();
        IRenderer &SFMLGraphicLib::getRenderer() noexcept;
        bool SFMLGraphicLib::isCloseRequested() const noexcept;
	protected:
	private:
};

extern "C"
{
    IGraphicLib *getInstance()
    {
        return new SFMLGraphicLib();
    }
}