//
// Created by roman on 17.10.2020.
//

#ifndef FLASH_BACKAUDIOEFFECTGENERATOR_H
#define FLASH_BACKAUDIOEFFECTGENERATOR_H

#include "../Generator.h"

namespace Generate {

    class BackAudioEffectGenerator : public Generator {
    public:
        BackAudioEffectGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) override;
    };
}

#endif //FLASH_BACKAUDIOEFFECTGENERATOR_H
