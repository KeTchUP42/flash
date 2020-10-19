//
// Created by roman on 19.10.2020.
//

#ifndef FLASH_MOBSAUDIOTRIGGER_H
#define FLASH_MOBSAUDIOTRIGGER_H

#include "../AudioTrigger.h"

namespace Triggers {

    class MobsAudioTrigger : public AudioTrigger {
    public:
        explicit MobsAudioTrigger(const Components::Area &area, const std::shared_ptr<sf::Music> &audio);

        ResultCodes verifyTrigger(Unite::Unifier *unifier) noexcept override;
    };
}

#endif //FLASH_MOBSAUDIOTRIGGER_H
