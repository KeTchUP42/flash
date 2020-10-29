//
// Created by roman on 29.10.2020.
//

#ifndef FLASH_SINGLEMOBSAUDIOTRIGGER_H
#define FLASH_SINGLEMOBSAUDIOTRIGGER_H

#include "../AudioTrigger.h"

namespace Triggers {

    class SingleMobsAudioTrigger : public AudioTrigger {
    public:
        explicit SingleMobsAudioTrigger(const Components::Area &area, const std::shared_ptr<sf::Music> &audio);

        ResultCodes verifyTrigger(Unite::Unifier *unifier) noexcept override;

    private:
        bool WAS_PLAYED = false;
    };
}

#endif //FLASH_SINGLEMOBSAUDIOTRIGGER_H
