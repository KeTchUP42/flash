//
// Created by roman on 08.10.2020.
//

#ifndef FLASH_GRAVITYPOINTEFFECTGENERATOR_H
#define FLASH_GRAVITYPOINTEFFECTGENERATOR_H

#include "../Generator.h"

namespace Generate {

    class GravityPointEffectGenerator : public Generator {
    public:
        GravityPointEffectGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) override;
    };
}

#endif //FLASH_GRAVITYPOINTEFFECTGENERATOR_H
