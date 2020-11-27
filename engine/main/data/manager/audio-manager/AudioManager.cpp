//
// Created by roman on 27.09.2020.
//
#include "AudioManager.h"
#include "../../../support/exceptions/custom/AudioFileCannotBeOpened.h"

std::shared_ptr<sf::Music> Managers::AudioManager::loadMusic(const std::string &filename) const {
    std::shared_ptr<sf::Music> music(new sf::Music());

    if (!music->openFromFile(AUDIO_DIRECTORY + "/" + filename)) {
        throw Exceptions::AudioFileCannotBeOpened("File " + filename + " cannot be opened.");
    }
    return music;
}