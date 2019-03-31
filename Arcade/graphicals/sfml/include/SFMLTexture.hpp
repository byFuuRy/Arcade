/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SFMLTexture
*/

#ifndef NCURSES_TEXTURE_HPP_
#define NCURSES_TEXTURE_HPP_

#include <SFML/Graphics/Texture.hpp>

#include "ATexture.hpp"

class SFMLTexture : public ATexture {
public:
	SFMLTexture(const void *buffer, const size_t &len);

	SFMLTexture(const SFMLTexture&) = default;
	SFMLTexture& operator=(const SFMLTexture&) = default;

    sf::Texture _texture;
};

#endif /* !NCURSES_TEXTURE_HPP_ */