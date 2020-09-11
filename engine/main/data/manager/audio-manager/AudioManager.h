//
// Created by roman on 23.08.2020.
//

#ifndef FLASH_AUDIOMANAGER_H
#define FLASH_AUDIOMANAGER_H

#include <string>
#include <memory>

#include "../../audio/player/AudioPlayer.h"

namespace Managers {

    /**
     * @brief The base class of the AudioManager class hierarchy.
     * @namespace Managers
     *
     * This class defines base AudioManager interface and fields.
     */
    class AudioManager {
    public:
        explicit AudioManager(const std::string &audioDirectory)
                : _audiofiles(audioDirectory) {}

        explicit AudioManager(const char *audioDirectory)
                : _audiofiles(audioDirectory) {}

        /**
         * @brief Method loads file from Audio directory.
         * @param filename File in audio directory.
         * @param Is loop? Can be useless.
         * @return New audio player.
         */
        virtual std::shared_ptr<Audio::AudioPlayer>
        loadAudioFile(const std::string &filename, bool loop) const = 0;

        virtual ~AudioManager() = default;

    protected:
        const std::string _audiofiles;
    };
}
#endif //FLASH_AUDIOMANAGER_H
