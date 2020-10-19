//
// Created by roman on 19.10.2020.
//

#include "MonsterAudioTrigger.h"

Triggers::MonsterAudioTrigger::MonsterAudioTrigger(const Components::Area &area, const std::shared_ptr<sf::Music> &audio)
        : AudioTrigger(area, audio) {}

Triggers::ResultCodes Triggers::MonsterAudioTrigger::verifyTrigger(Unite::Unifier *unifier) noexcept {

    for (const std::shared_ptr<Mobs::Monster> &monster: unifier->getMonsters()) {

        if (MathUtils::collision(*this, *monster)) {
            if (m_audio->getStatus() != sf::SoundSource::Playing) {
                m_audio->setPlayingOffset(sf::Time());
                m_audio->play();
            }
        }
    }
    return ResultCodes::OK;
}
