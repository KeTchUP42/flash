//
// Created by roman on 17.08.2020.
//
#include "AudioPlayback.h"

#include <SFML/Audio.hpp>

void Audio::playMusic(const std::string &audiofile) noexcept {
    sf::Music music;
    if (!music.openFromFile(audiofile))
        return;

    music.play();

    while (music.getStatus() == sf::Music::Playing) {
        sf::sleep(sf::milliseconds(100));
    }
}

void Audio::playMusicAsync(const std::string &audiofile) noexcept {
    sf::Music music;
    if (!music.openFromFile(audiofile))
        return;

    music.play();
}

void Audio::playSound(const std::string &audiofile) noexcept {
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(audiofile))
        return;

    sf::Sound sound(buffer);
    sound.play();

    while (sound.getStatus() == sf::Sound::Playing) {
        sf::sleep(sf::milliseconds(100));
    }
}

void Audio::playSoundAsync(const std::string &audiofile) noexcept {
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(audiofile))
        return;

    sf::Sound sound(buffer);
    sound.play();
}