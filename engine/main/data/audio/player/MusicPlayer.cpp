//
// Created by roman on 17.08.2020.
//
#include "MusicPlayer.h"
#include "../../../other/exceptions/custom/AudioFileCannotBeOpened.h"

Audio::MusicPlayer::MusicPlayer(const std::string &filename, bool loop) {
    std::shared_ptr<sf::Music> musicSource(new sf::Music());

    if (!musicSource->openFromFile(filename)) {
        throw PreferredExceptions::AudioFileCannotBeOpened("File " + filename + " cannot be opened.");
    }
    musicSource->setLoop(loop);
    _sound = std::move(musicSource);
}

void Audio::MusicPlayer::play() {
    _sound->play();

    while (_sound->getStatus() == sf::Music::Playing) {
        sf::sleep(sf::milliseconds(100));
    }
}

void Audio::MusicPlayer::playAsync() {
    _sound->play();
}

void Audio::MusicPlayer::stop() {
    _sound->stop();
}

void Audio::MusicPlayer::pause() {
    _sound->pause();
}

