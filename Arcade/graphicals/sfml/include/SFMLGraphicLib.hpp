/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SFMLGraphicLib
*/

#ifndef NCURSES_GRAPHICAL_LIB_HPP_
#define NCURSES_GRAPHICAL_LIB_HPP_

#include "IGraphicLib.hpp"
#include "SFMLRenderer.hpp"
#include "SFMLTexture.hpp"
#include "SFMLSprite.hpp"
#include "ATexture.hpp"
#include "Rect.hpp"

class SFMLGraphicLib : public IGraphicLib {
public:
    SFMLGraphicLib() = default;
    ~SFMLGraphicLib() = default;
    
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

    SFMLRenderer _renderer{};
};

extern "C"
{
    IGraphicLib *getGraphicalInstance()
    {
        return new SFMLGraphicLib();
    }
}

#endif /* !NCURSES_GRAPHICAL_LIB_HPP_ */