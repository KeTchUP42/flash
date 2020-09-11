//
// Created by roman on 23.08.2020.
//

#ifndef FLASH_MUSICMANAGER_H
#define FLASH_MUSICMANAGER_H

#include "AudioManager.h"

namespace Managers {

    class MusicManager : public AudioManager {
    public:
        explicit MusicManager(const std::string &audioDirectory)
                : AudioManager(audioDirectory) {}

        explicit MusicManager(const char *audioDirectory)
                : AudioManager(audioDirectory) {}

        std::shared_ptr<Audio::AudioPlayer>
        loadAudioFile(const std::string &filename, bool loop) const override;
    };
}

#endif //FLASH_MUSICMANAGER_H
