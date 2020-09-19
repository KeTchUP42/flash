//
// Created by roman on 17.08.2020.
//

#ifndef FLASH_SOUNDPLAYER_H
#define FLASH_SOUNDPLAYER_H

#include "AudioPlayer.h"

namespace Audio {

    class SoundPlayer : public AudioPlayer {
    public:
        explicit SoundPlayer(const sf::SoundBuffer &buffer);

        explicit SoundPlayer(const std::shared_ptr<sf::Sound> &sound);

        explicit SoundPlayer(sf::Sound *sound);

        void play() override;

        void playAsync() override;

        void stop() override;

        void pause() override;
    };
}

#endif //FLASH_SOUNDPLAYER_H
