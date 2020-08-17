//
// Created by roman on 17.08.2020.
//

#ifndef FLASH_AUDIOPLAYER_H
#define FLASH_AUDIOPLAYER_H

#include <SFML/Audio.hpp>
#include <string>
#include <memory>

namespace Audio {

    /**
     * @brief The base class of the AudioPlayer class hierarchy.
     * @namespace Audio
     *
     * This class defines base AudioPlayer interface and fields.
    */
    class AudioPlayer {
    public:

        AudioPlayer() = default;

        explicit AudioPlayer(const std::shared_ptr<sf::SoundSource> &soundSource)
                : _soundSource(soundSource) {}

        explicit AudioPlayer(sf::SoundSource *soundSource)
                : _soundSource(soundSource) {}

        AudioPlayer &operator=(const AudioPlayer &) = delete;

        /**
         * @brief Method plays audio file.
         */
        virtual void play() = 0;

        /**
         * @brief Method plays audio file async.
         */
        virtual void playAsync() = 0;

        /**
         * @brief Method stops audio.
         */
        virtual void stop() = 0;

        /**
         * @brief Method pauses audio.
         */
        virtual void pause() = 0;

        /**
         * @brief Method returns origin SoundSource.
         * @return sf::SoundSource
         */
        sf::SoundSource *const getSoundSource() const noexcept {
            return _soundSource.get();
        }

        virtual ~AudioPlayer() noexcept = default;

    protected:
        std::shared_ptr<sf::SoundSource> _soundSource;
    };

}

#endif //FLASH_AUDIOPLAYER_H
