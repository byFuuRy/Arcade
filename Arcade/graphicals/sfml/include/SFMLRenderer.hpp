/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SFMLRenderer
*/

#ifndef NCURSES_RENDERER_HPP_
#define NCURSES_RENDERER_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics.hpp>
#include <stdexcept>

#include "IRenderer.hpp"
#include "SFMLSprite.hpp"

class SFMLRenderer : public IRenderer {
public:
	SFMLRenderer();
	~SFMLRenderer();

	void drawRectangle(const Rect &rect, const Color &color, bool fill = true);
	void drawText(const std::string &text, uint8_t fontSize, const Vector &pos, const Color &color);
	void drawSprite(const ASprite *sprite);

	void display();
	void clear();

	sf::RenderWindow *_window = nullptr;

protected:
    sf::Font _font;
};

#endif /* !NCURSES_RENDERER_HPP_ */