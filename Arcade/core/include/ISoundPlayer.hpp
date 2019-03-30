/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** ISoundPlayer
*/

#ifndef ISOUNDPLAYER_HPP_
#define ISOUNDPLAYER_HPP_

#include <string>
#include <cstdint>

class ISoundPlayer {
public:
	virtual void playSound(const std::string &soundPath) = 0;
	virtual void playMusic(const std::string &musicPath) = 0;
	virtual void setVolume(uint8_t value) noexcept = 0;
	virtual uint8_t getVolume() const noexcept = 0;
};

#endif /* !ISOUNDPLAYER_HPP_ */
