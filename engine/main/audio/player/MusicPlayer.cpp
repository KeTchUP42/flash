//
// Created by roman on 17.08.2020.
//
#include <cstring>

#include "MusicPlayer.h"
#include "../../general/exceptions/custom/AudioFileCanNotBeOpened.h"

Audio::MusicPlayer::MusicPlayer(const std::string &filename, bool loop) {
    std::shared_ptr<sf::Music> musicSource(new sf::Music());

    if (!musicSource->openFromFile(filename)) {
        throw PreferredExceptions::AudioFileCanNotBeOpened(
                std::strcat(const_cast<char *>(filename.c_str()), " cannot be opened."));
    }
    musicSource->setLoop(loop);
    _soundSource = std::move(musicSource);
}

void Audio::MusicPlayer::play() {
    _soundSource->play();

    while (_soundSource->getStatus() == sf::Music::Playing) {
        sf::sleep(sf::milliseconds(100));
    }
}

void Audio::MusicPlayer::playAsync() {
    _soundSource->play();
}

void Audio::MusicPlayer::stop() {
    _soundSource->stop();
}

void Audio::MusicPlayer::pause() {
    _soundSource->pause();
}

