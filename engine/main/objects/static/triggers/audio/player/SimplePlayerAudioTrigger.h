//
// Created by roman on 15.10.2020.
//

#ifndef FLASH_SIMPLEPLAYERAUDIOTRIGGER_H
#define FLASH_SIMPLEPLAYERAUDIOTRIGGER_H

#include "../AudioTrigger.h"

namespace Triggers {

    class SimplePlayerAudioTrigger : public AudioTrigger {
    public:
        explicit SimplePlayerAudioTrigger(const Components::Area &area, const std::shared_ptr<sf::Music> &audio);

        ResultCodes verifyTrigger(Unite::Unifier *unifier) noexcept override;
    };
}

#endif //FLASH_SIMPLEPLAYERAUDIOTRIGGER_H
