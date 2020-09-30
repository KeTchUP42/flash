//
// Created by roman on 30.09.2020.
//

#ifndef FLASH_GRAVITYEFFECTGENERATOR_H
#define FLASH_GRAVITYEFFECTGENERATOR_H

#include "../Generator.h"

namespace Generating {

    class GravityEffectGenerator : public Generator {
    public:
        GravityEffectGenerator(SourcePool &pool);

        void load(const IniProcessorUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) override;
    };
}

#endif //FLASH_GRAVITYEFFECTGENERATOR_H
