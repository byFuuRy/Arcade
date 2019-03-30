/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Atexture
*/

#pragma once

#include <cstddef>

class ATexture {
public:
    ATexture(const void* buffer, const size_t& len);
    virtual ~ATexture() = default;

    ATexture(const ATexture&) = delete;
    ATexture& operator=(const ATexture&) = delete;

    virtual const void* getBuffer() const noexcept final;
    virtual const size_t& getBufferLength() const noexcept final;

protected:
    const void* _buffer;
    const size_t _len;
};