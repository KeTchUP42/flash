//
// Created by roman on 17.08.2020.
//
#include "SoundPlayer.h"

Audio::SoundPlayer::SoundPlayer(const sf::SoundBuffer &buffer)
        : AudioPlayer(std::shared_ptr<sf::SoundSource>(new sf::Sound(buffer))) {}

Audio::SoundPlayer::SoundPlayer(const std::shared_ptr<sf::Sound> &sound) : AudioPlayer(sound) {}

Audio::SoundPlayer::SoundPlayer(sf::Sound *sound) : AudioPlayer(sound) {}

void Audio::SoundPlayer::play() {
    _sound->play();

    while (_sound->getStatus() == sf::Sound::Playing) {
        sf::sleep(sf::milliseconds(100));
    }
}

void Audio::SoundPlayer::playAsync() {
    _sound->play();
}

void Audio::SoundPlayer::stop() {
    _sound->stop();
}

void Audio::SoundPlayer::pause() {
    _sound->pause();
}
