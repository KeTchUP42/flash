//
// Created by roman on 17.08.2020.
//

#ifndef FLASH_SOUNDPLAYER_H
#define FLASH_SOUNDPLAYER_H

#include "AudioPlayer.h"

namespace Audio {

    class SoundPlayer : public AudioPlayer {
    public:

        explicit SoundPlayer(const std::shared_ptr<sf::Sound> &sound)
                : AudioPlayer(sound) {}

        explicit SoundPlayer(const sf::SoundBuffer &soundBuffer)
                : AudioPlayer(std::shared_ptr<sf::SoundSource>(new sf::Sound(soundBuffer))) {}

        explicit SoundPlayer(sf::Sound *sound)
                : AudioPlayer(sound) {}

        void play() override;

        void playAsync() override;

        void stop() override;

        void pause() override;
    };
}

#endif //FLASH_SOUNDPLAYER_H
