//
// Created by roman on 23.08.2020.
//

#include "MusicManager.h"
#include "../../audio/player/MusicPlayer.h"

std::shared_ptr<Audio::AudioPlayer>
Managers::MusicManager::createAudioPlayerForFile(const std::string &filename, bool loop) const {
    return std::shared_ptr<Audio::AudioPlayer>(new Audio::MusicPlayer(_audioDirectory + "/" + filename, loop));
}
