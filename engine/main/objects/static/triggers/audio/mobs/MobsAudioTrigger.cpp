//
// Created by roman on 19.10.2020.
//

#include "MobsAudioTrigger.h"

Triggers::MobsAudioTrigger::MobsAudioTrigger(const Components::Area &area, const std::shared_ptr<sf::Music> &audio)
        : AudioTrigger(area, audio) {}

Triggers::ResultCodes Triggers::MobsAudioTrigger::verifyTrigger(Unite::Unifier *unifier) noexcept {
    if (m_audio->getStatus() == sf::SoundSource::Playing) return ResultCodes::OK;

    for (const std::shared_ptr<Mobs::Mob> &mob: unifier->getMobs()) {

        if (MathUtils::collision(*this, *mob)) {
            m_audio->setPlayingOffset(sf::Time());
            m_audio->play();
            break;
        }
    }
    return ResultCodes::OK;
}
