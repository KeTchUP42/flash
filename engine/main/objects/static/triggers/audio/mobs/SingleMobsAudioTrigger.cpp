//
// Created by roman on 29.10.2020.
//

#include "SingleMobsAudioTrigger.h"

Triggers::SingleMobsAudioTrigger::SingleMobsAudioTrigger(const Components::Area &area, const std::shared_ptr<sf::Music> &audio)
        : AudioTrigger(area, audio) {}

Triggers::ResultCodes Triggers::SingleMobsAudioTrigger::verifyTrigger(Unite::Unifier *unifier) noexcept {
    if (WAS_PLAYED) return ResultCodes::OK;

    for (const std::shared_ptr<Mobs::Mob> &mob: unifier->getMobs()) {

        if (MathUtils::collision(*this, *mob)) {
            m_audio->play();
            WAS_PLAYED = true;
            break;
        }
    }
    return ResultCodes::OK;
}
