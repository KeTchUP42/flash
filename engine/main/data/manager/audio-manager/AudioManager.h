//
// Created by roman on 23.08.2020.
//

#ifndef FLASH_AUDIOMANAGER_H
#define FLASH_AUDIOMANAGER_H

#include <string>
#include <memory>

#include "../../audio/player/AudioPlayer.h"

namespace DataManagers {

    /**
     * @brief The base class of the AudioManager class hierarchy.
     * @namespace DataManagers
     *
     * This class defines base AudioManager interface and fields.
     */
    class AudioManager {
    public:
        explicit AudioManager(const std::string &audioDirectory)
                : _audioDirectory(audioDirectory) {}

        explicit AudioManager(const char *audioDirectory)
                : _audioDirectory(audioDirectory) {}

        /**
         * @brief Method loads file from Audio directory.
         * @param filename File in audio directory.
         * @param Is loop? Can be useless.
         * @return std::shared_ptr<Audio::AudioPlayer>
         */
        virtual std::shared_ptr<Audio::AudioPlayer>
        createAudioPlayerForFile(const std::string &filename, bool loop) const = 0;

        virtual ~AudioManager() = default;

    protected:
        const std::string _audioDirectory;
    };
}
#endif //FLASH_AUDIOMANAGER_H