//
// Created by roman on 17.08.2020.
//
#include "SoundPlayer.h"

void Audio::SoundPlayer::play() {
    _soundSource->play();

    while (_soundSource->getStatus() == sf::Sound::Playing) {
        sf::sleep(sf::milliseconds(100));
    }
}

void Audio::SoundPlayer::playAsync() {
    _soundSource->play();
}

void Audio::SoundPlayer::stop() {
    _soundSource->stop();
}

void Audio::SoundPlayer::pause() {
    _soundSource->pause();
}
