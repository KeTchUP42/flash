//
// Created by roman on 15.10.2020.
//

#ifndef FLASH_PLAYERAUDIOTRIGGER_H
#define FLASH_PLAYERAUDIOTRIGGER_H

#include "../AudioTrigger.h"

namespace Triggers {

    class PlayerAudioTrigger : public AudioTrigger {
    public:
        PlayerAudioTrigger(const Components::Area &area, const std::shared_ptr<sf::Music> &audio);

        ResultCodes verifyTrigger(Unite::Unifier *unifier) noexcept override;
    };
}

#endif //FLASH_PLAYERAUDIOTRIGGER_H
