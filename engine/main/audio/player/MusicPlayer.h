//
// Created by roman on 17.08.2020.
//

#ifndef FLASH_MUSICPLAYER_H
#define FLASH_MUSICPLAYER_H

#include "AudioPlayer.h"

namespace Audio {
    class MusicPlayer : public AudioPlayer {
    public:
        explicit MusicPlayer(const std::string &audiofile, bool loop = false);

        explicit MusicPlayer(const std::shared_ptr<sf::Music> &soundSource) : AudioPlayer(soundSource) {}

        explicit MusicPlayer(sf::Music *soundSource) : AudioPlayer(soundSource) {}

        void play() override;

        void playAsync() override;

        void stop() override;

        void pause() override;
    };
}

#endif //FLASH_MUSICPLAYER_H
