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
    TTF_Init();
    _font = TTF_OpenFont("res/arcade.ttf", 24);
    if (_font == nullptr)
        throw std::runtime_error(TTF_GetError());
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
    SDLSprite::getRenderer(_renderer);
}

SDLRenderer::~SDLRenderer()
{
    SDL_Quit();
}

void SDLRenderer::drawRectangle(const Rect& rect, const Color& color, bool fill)
{
    SDL_Rect sdlRect;

    SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, color.a);
    sdlRect.x = rect.pos.x * 800.0;
    sdlRect.y = rect.pos.y * 800.0;
    sdlRect.w = rect.size.x * 800.0;
    sdlRect.h = rect.size.y * 800.0;
    SDL_RenderDrawRect(_renderer, &sdlRect);
}

void SDLRenderer::drawText(const std::string& text, uint8_t size, const Vector& pos, const Color& color)
{
    SDL_Color Color = { 
        color.r,
        color.g,
        color.b,
        color.a
    };
    SDL_Surface *surfaceMessage = TTF_RenderText_Solid(_font, text.c_str(), Color);
    SDL_Texture *Message = SDL_CreateTextureFromSurface(_renderer, surfaceMessage);
    SDL_Rect Message_rect;

    Message_rect.x = pos.x * _size.first;
    Message_rect.y = pos.y * _size.second;
    Message_rect.w = size * 100;
    Message_rect.h = size * 70;
    SDL_RenderCopy(_renderer, Message, NULL, &Message_rect);
}

void SDLRenderer::display()
{
    SDL_RenderPresent(_renderer);
}

void SDLRenderer::clear()
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
}

void SDLRenderer::drawSprite(const ASprite* sprite)
{
    const SDLSprite* texture = dynamic_cast<const SDLSprite*>(sprite);
    SDL_RenderCopy(_renderer, texture->_sprite, &texture->_rect, &texture->_pos);
}
