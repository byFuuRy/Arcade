/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** NcursesTexture
*/

#ifndef NCURSES_TEXTURE_HPP_
#define NCURSES_TEXTURE_HPP_

#include "ATexture.hpp"

class NCursesTexture : public ATexture {
public:
	NCursesTexture(const void *buffer, const size_t &len);

	NCursesTexture(const NCursesTexture&) = default;
	NCursesTexture& operator=(const NCursesTexture&) = default;
};

#endif /* !NCURSES_TEXTURE_HPP_ */