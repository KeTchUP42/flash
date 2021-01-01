//
// Created by roman on 29.10.2020.
//

#ifndef FLASH_SINGLEPLAYERAUDIOTRIGGER_H
#define FLASH_SINGLEPLAYERAUDIOTRIGGER_H

#include "../AudioTrigger.h"

namespace Triggers {

    class SinglePlayerAudioTrigger : public AudioTrigger {
    public:
        SinglePlayerAudioTrigger(const Components::Area &area, const std::shared_ptr<sf::Music> &audio);

        ResultCodes verifyTrigger(Unite::Unifier *unifier) noexcept override;

    private:
        bool WAS_PLAYED = false;
    };
}

#endif //FLASH_SINGLEPLAYERAUDIOTRIGGER_H
