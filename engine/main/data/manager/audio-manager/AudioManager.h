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
     * @brief The class provides convenient access to audio data.
     * @namespace Managers
     *
     * This class defines AudioManager realization.
     */
    class AudioManager {
    public:
        explicit AudioManager(const std::string &audioDirectory)
                : AUDIO_DIRECTORY(audioDirectory) {}

        explicit AudioManager(const char *audioDirectory)
                : AUDIO_DIRECTORY(audioDirectory) {}

        /**
         * @brief Method loads file from audio directory.
         * @param filename File in audio directory.
         * @return New sf::Music.
         */
        std::shared_ptr<sf::Music> loadMusic(const std::string &filename) const;

        virtual ~AudioManager() = default;

    private:
        const std::string AUDIO_DIRECTORY;
    };
}
#endif //FLASH_AUDIOMANAGER_H
