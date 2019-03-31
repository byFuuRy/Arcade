/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SFMLRenderer
*/

#include "SFMLRenderer.hpp"

SFMLRenderer::SFMLRenderer()
{
    _size = {800, 800};
    this->_font.loadFromFile("res/arcade.ttf");
    this->_window = new sf::RenderWindow(sf::VideoMode(_size.x, _size.y), "Arcade");
}

SFMLRenderer::~SFMLRenderer()
{
    this->_window->close();
}

void SFMLRenderer::drawRectangle(const Rect &rect, const Color &color, bool fill)
{
    sf::Vector2f size(rect.size.x * _size.x, rect.size.y * _size.y);
    sf::RectangleShape rectangle(size);
    sf::Color sfColor(color.r, color.g, color.b, color.a);

    if (fill)
        rectangle.setFillColor(sfColor);
    else
        rectangle.setFillColor(sf::Color::Transparent);
    rectangle.setPosition(rect.pos.x * _size.x, rect.pos.y * _size.y);
    _window->draw(rectangle);
}

void SFMLRenderer::drawText(const std::string &text, uint8_t size, const Vector &pos, const Color &color)
{
    sf::Text sfText;
    sf::Color sfColor(color.r, color.g, color.b, color.a);
    sf::Vector2f sfVector2f(pos.x * _size.x, pos.y * _size.y);

    sfText.setFillColor(sfColor);
    sfText.setFont(_font);
    sfText.setString(text);
    sfText.setPosition(sfVector2f);
    //sfText.setScale({static_cast<float>(size), static_cast<float>(size)});
    sfText.setCharacterSize(size);
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
