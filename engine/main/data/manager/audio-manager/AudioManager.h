//
// Created by roman on 23.08.2020.
//

#ifndef FLASH_AUDIOMANAGER_H
#define FLASH_AUDIOMANAGER_H

#include <string>
#include <memory>
#include <SFML/Audio.hpp>

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
                : AUDIO_DIRECTORY(audioDirectory) {}

        explicit AudioManager(const char *audioDirectory)
                : AUDIO_DIRECTORY(audioDirectory) {}

        /**
         * @brief Method loads file from Audio directory.
         * @param filename File in audio directory.
         * @return New audio sf::Music.
         */
        virtual std::shared_ptr<sf::Music>
        loadMusic(const std::string &filename) const = 0;

        virtual ~AudioManager() = default;

    protected:
        const std::string AUDIO_DIRECTORY;
    };
}
#endif //FLASH_AUDIOMANAGER_H
