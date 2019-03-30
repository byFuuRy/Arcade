/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** NcursesTexture
*/

#pragma once

#include "ATexture.hpp"

class NcursesTexture : public ATexture {
	public:
		NcursesTexture(const void* buffer, const size_t& len);

        NcursesTexture(const NcursesTexture&) = default;
        NcursesTexture& operator=(const NcursesTexture&) = default;

        const void* getBuffer() const noexcept final;
        const size_t& getBufferLength() const noexcept final;

	protected:
	private:
};