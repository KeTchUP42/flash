//
// Created by roman on 30.09.2020.
//

#ifndef FLASH_BACKGROUNDSPRITEGENERATOR_H
#define FLASH_BACKGROUNDSPRITEGENERATOR_H

#include "../Generator.h"

namespace Generating {

    class BackgroundSpriteGenerator : public Generator {
    public:
        BackgroundSpriteGenerator(SourcePool &pool);

        void load(const IniProcessorUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) override;
    };
}

#endif //FLASH_BACKGROUNDSPRITEGENERATOR_H
