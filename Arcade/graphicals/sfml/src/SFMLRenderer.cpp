/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SFMLRenderer
*/

#include "SFMLRenderer.hpp"

#define RGBN(x) x * 1000 / 255

SFMLRenderer::SFMLRenderer()
{
    this->_font.loadFromFile("res/arcade.ttf");
    this->_window = new sf::RenderWindow(sf::VideoMode(800, 800), "Arcade");
}

SFMLRenderer::~SFMLRenderer()
{
    this->_window->close();
}

void SFMLRenderer::drawRectangle(const Rect &rect, const Color &color, bool fill)
{
    sf::Vector2f size(rect.size.x, rect.size.y);
    sf::RectangleShape rectangle(size);

    rectangle.setPosition(rect.pos.x, rect.pos.y);
    _window->draw(rectangle);
}

void SFMLRenderer::drawText(const std::string &text, uint8_t, const Vector &pos, const Color &color)
{
    sf::Text sfText;
    sf::Color sfColor(color.r, color.g, color.b, color.a);
    sf::Vector2f sfVector2f(pos.x, pos.y);

    sfText.setColor(sfColor);
    sfText.setFont(_font);
    sfText.setString(text);
    sfText.setPosition(sfVector2f);
    _window->draw(sfText);
}

void SFMLRenderer::display()
{
    _window->display();
}

void SFMLRenderer::clear()
{
    _window->clear(sf::Color::Black);
}

void SFMLRenderer::drawSprite(const ASprite *sprite)
{
    _window->draw(dynamic_cast<const SFMLSprite *>(sprite)->_sprite);
}
