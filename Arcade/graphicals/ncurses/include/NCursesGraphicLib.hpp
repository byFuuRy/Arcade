/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** NCursesGraphicLib
*/

#ifndef NCURSES_GRAPHICAL_LIB_HPP_
#define NCURSES_GRAPHICAL_LIB_HPP_

#include "IGraphicLib.hpp"
#include "NCursesRenderer.hpp"
#include "NCursesTexture.hpp"
#include "NCursesSprite.hpp"
#include "ATexture.hpp"
#include "Rect.hpp"

class NCursesGraphicLib : public IGraphicLib {
public:
    NCursesGraphicLib() = default;
    ~NCursesGraphicLib() = default;
    
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

    NCursesRenderer _renderer{};
};

extern "C"
{
    IGraphicLib *getGraphicalInstance()
    {
        return new NCursesGraphicLib();
    }
}

#endif /* !NCURSES_GRAPHICAL_LIB_HPP_ */