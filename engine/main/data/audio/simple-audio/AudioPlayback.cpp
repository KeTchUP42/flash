//
// Created by roman on 17.08.2020.
//
#include "AudioPlayback.h"

#include <SFML/Audio.hpp>

void Audio::playMusic(const std::string &filename) noexcept {
    sf::Music music;
    if (!music.openFromFile(filename))
        return;

    music.play();

    while (music.getStatus() == sf::Music::Playing) {
        sf::sleep(sf::milliseconds(100));
    }
}

void Audio::playMusicAsync(const std::string &filename) noexcept {
    sf::Music music;
    if (!music.openFromFile(filename))
        return;

    music.play();
}

void Audio::playSound(const std::string &filename) noexcept {
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(filename))
        return;

    sf::Sound sound(buffer);
    sound.play();

    while (sound.getStatus() == sf::Sound::Playing) {
        sf::sleep(sf::milliseconds(100));
    }
}

void Audio::playSoundAsync(const std::string &filename) noexcept {
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(filename))
        return;

    sf::Sound sound(buffer);
    sound.play();
}