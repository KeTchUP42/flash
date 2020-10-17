//
// Created by roman on 17.10.2020.
//

#include "BackAudioEffect.h"

Effects::BackAudioEffect::BackAudioEffect(const std::shared_ptr<sf::Music> &audio) : AudioEffect(audio) {}

void Effects::BackAudioEffect::applyEffect(Unite::Unifier *unifier) {
    if ((m_audio->getStatus() != sf::SoundSource::Playing) && (m_audio->getPlayingOffset() == sf::Time::Zero)) {
        m_audio->play();
    }
}
