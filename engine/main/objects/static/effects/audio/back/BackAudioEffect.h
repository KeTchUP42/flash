//
// Created by roman on 17.10.2020.
//

#ifndef FLASH_BACKAUDIOEFFECT_H
#define FLASH_BACKAUDIOEFFECT_H

#include "../AudioEffect.h"

namespace Effects {

    class BackAudioEffect : public AudioEffect {
    public:
        BackAudioEffect(const std::shared_ptr<sf::Music> &audio);

        void applyEffect(Unite::Unifier *unifier) override;
    };
}

#endif //FLASH_BACKAUDIOEFFECT_H
