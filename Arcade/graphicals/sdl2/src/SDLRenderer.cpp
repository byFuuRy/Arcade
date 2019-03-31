/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SDLRenderer
*/

#include "SDLRenderer.hpp"

SDLRenderer::SDLRenderer()
{
    _size = { 800, 800 };
    _font = TTF_OpenFont("res/arcade.ttf", 24);
    if (_font == nullptr)
        throw std::runtime_error("Cannot load res/arcade.ttf");
    SDL_Init(SDL_INIT_VIDEO);
    _window = SDL_CreateWindow(
        "Arcade",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        800,
        800,
        0);
    if (_window == nullptr)
        throw std::runtime_error("Cannot open SDL2 window");
    if (_renderer == nullptr)
        _renderer = SDL_CreateRenderer(_window, -1, 0);
    if (_renderer == nullptr)
        throw std::runtime_error("Cannot open SDL2 window");
}

SDLRenderer::~SDLRenderer()
{
    SDL_Quit();
}

void SDLRenderer::drawRectangle(const Rect& rect, const Color& color, bool fill)
{
    SDL_Rect sdlRect;

    sdlRect.x = rect.pos.x;
    sdlRect.y = rect.pos.y;
    sdlRect.x = rect.size.x;
    sdlRect.y = rect.size.y;
    SDL_RenderDrawRect(_renderer, &sdlRect);
}

void SDLRenderer::drawText(const std::string& text, uint8_t size, const Vector& pos, const Color& color)
{
    SDL_Color Color = { color.r, color.g, color.b };
    SDL_Surface *surfaceMessage = TTF_RenderText_Solid(_font, text.c_str(), Color);
    SDL_Texture *Message = SDL_CreateTextureFromSurface(_renderer, surfaceMessage);
    SDL_Rect Message_rect;
    Message_rect.x = pos.x;
    Message_rect.y = pos.y;
    Message_rect.w = size;
    Message_rect.h = size;
    SDL_RenderCopy(_renderer, Message, NULL, &Message_rect);
}

void SDLRenderer::display()
{
    SDL_RenderPresent(_renderer);
}

void SDLRenderer::clear()
{
    SDL_RenderClear(_renderer);
}

void SDLRenderer::drawSprite(const ASprite* sprite)
{
    const SDLSprite* texture = dynamic_cast<const SDLSprite*>(sprite);
    SDL_RenderCopy(_renderer, texture->_sprite, &texture->_rect, &texture->_pos);
}
