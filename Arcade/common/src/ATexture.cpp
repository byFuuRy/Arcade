/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** ATexture
*/

#include "ATexture.hpp"

ATexture::ATexture(const void* buffer, const size_t& len)
	: _buffer(buffer), _len(len)
{}

const void *ATexture::getBuffer() const noexcept
{
	return this->_buffer;
}

const size_t &ATexture::getBufferLength() const noexcept
{
	return this->_len;
}