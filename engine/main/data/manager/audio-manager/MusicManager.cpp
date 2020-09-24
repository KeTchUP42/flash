//
// Created by roman on 23.08.2020.
//

#include "MusicManager.h"
#include "../../../other/exceptions/custom/AudioFileCannotBeOpened.h"

std::shared_ptr<sf::Music> Managers::MusicManager::loadMusic(const std::string &filename) const {
    std::shared_ptr<sf::Music> music(new sf::Music());

    if (!music->openFromFile(AUDIO_DIRECTORY + "/" + filename)) {
        throw PreferredExceptions::AudioFileCannotBeOpened("File " + filename + " cannot be opened.");
    }
    return music;
}
