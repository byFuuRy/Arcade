/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SFMLTexture
*/

#include "SFMLTexture.hpp"

SFMLTexture::SFMLTexture(const void *buffer, const size_t& len)
	: ATexture(buffer, len)
{
    this->_texture.loadFromMemory(buffer, len);
}
