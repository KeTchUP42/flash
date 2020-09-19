//
// Created by roman on 19.09.2020.
//

#include "AudioPlayer.h"

Audio::AudioPlayer::AudioPlayer(const std::shared_ptr<sf::SoundSource> &sound) : _sound(sound) {}

Audio::AudioPlayer::AudioPlayer(sf::SoundSource *sound) : _sound(sound) {}

sf::SoundSource *const Audio::AudioPlayer::getSoundSource() const noexcept {
    return _sound.get();
}

