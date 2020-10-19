//
// Created by roman on 19.10.2020.
//

#ifndef FLASH_MONSTERAUDIOTRIGGER_H
#define FLASH_MONSTERAUDIOTRIGGER_H

#include "../AudioTrigger.h"

namespace Triggers {

    class MonsterAudioTrigger : public AudioTrigger {
    public:
        explicit MonsterAudioTrigger(const Components::Area &area, const std::shared_ptr<sf::Music> &audio);

        ResultCodes verifyTrigger(Unite::Unifier *unifier) noexcept override;
    };
}

#endif //FLASH_MONSTERAUDIOTRIGGER_H
