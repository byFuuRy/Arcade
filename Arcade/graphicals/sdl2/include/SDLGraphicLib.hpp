/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SDLGraphicLib
*/

#ifndef NCURSES_GRAPHICAL_LIB_HPP_
#define NCURSES_GRAPHICAL_LIB_HPP_

#include "IGraphicLib.hpp"
#include "SDLRenderer.hpp"
#include "SDLTexture.hpp"
#include "SDLSprite.hpp"
#include "ATexture.hpp"
#include "Rect.hpp"

class SDLGraphicLib : public IGraphicLib {
public:
    SDLGraphicLib() = default;
    ~SDLGraphicLib() = default;

    uint8_t getGameKeyState() const noexcept;
    uint8_t getCoreKeyState() const noexcept;
    void sendGameKeyInput(GameKey) noexcept {}
    void sendCoreKeyInput(CoreKey) noexcept {}
    void pollEvents();

    IRenderer &getRenderer() noexcept;
    bool isCloseRequested() const noexcept;

    virtual ATexture *createTexture(const void *buffer, const size_t &len);
    virtual ASprite *createSprite(const ATexture *texture, const Rect &spriteSheetRect, const Rect &posAndSize);

private:
    uint8_t _gameKey = 0;
    uint8_t _coreKey = 0;
    bool _close = false;

    SDLRenderer _renderer{};
};

extern "C"
{
    IGraphicLib *getGraphicalInstance()
    {
        return new SDLGraphicLib();
    }
}

#endif /* !NCURSES_GRAPHICAL_LIB_HPP_ */