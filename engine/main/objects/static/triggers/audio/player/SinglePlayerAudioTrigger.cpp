//
// Created by roman on 29.10.2020.
//

#include "SinglePlayerAudioTrigger.h"

Triggers::SinglePlayerAudioTrigger::SinglePlayerAudioTrigger(const Components::Area &area, const std::shared_ptr<sf::Music> &audio)
        : AudioTrigger(area, audio) {}

Triggers::ResultCodes Triggers::SinglePlayerAudioTrigger::verifyTrigger(Unite::Unifier *unifier) noexcept {
    if (WAS_PLAYED) return ResultCodes::OK;

    for (Mobs::Player *player: unifier->getPlayers()) {

        if (Material::OptimizedCollision<Possibilities::MaterialRectangle, Mobs::Player>(*this, *player)) {
            m_audio->play();
            WAS_PLAYED = true;
            break;
        }
    }
    return ResultCodes::OK;
}
