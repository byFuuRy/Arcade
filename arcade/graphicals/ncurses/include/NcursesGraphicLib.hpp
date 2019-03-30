/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** NcursesGraphicLib
*/

#pragma once

#include <unordered_map>

#include "IGraphicLib.hpp"
#include "IGame.hpp"

class NcursesGraphicLib : public IGraphicLib 
{
    public:
		NcursesGraphicLib() = default;
		~NcursesGraphicLib() = default;
        uint8_t NcursesGraphicLib::getCoreKeyState() const noexcept;
        uint8_t NcursesGraphicLib::getGameKeyState() const noexcept;
        void sendGameKeyInput(GameKey input) noexcept;
        void sendCoreKeyInput(CoreKey input) noexcept;
        void NcursesGraphicLib::pollEvents();
        IRenderer &NcursesGraphicLib::getRenderer() noexcept;
        bool NcursesGraphicLib::isCloseRequested() const noexcept;
        virtual ATexture *createTexture(const void *buffer, const size_t &len);
	    virtual ASprite *createSprite(const ATexture *texture, const Rect &spriteSheetRect, const Rect &posAndSize);

        IRenderer *_renderer;
        std::unordered_map<int, IGraphicLib::GameKey> _keymap;
        std::unordered_map<int, IGraphicLib::CoreKey> _coremap;
        int _key;
	protected:
	private:
};

extern "C"
{
    IGraphicLib *getGraphicalInstance()
    {
        return new NcursesGraphicLib();
    }
}