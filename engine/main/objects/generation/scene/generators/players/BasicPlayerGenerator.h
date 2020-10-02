//
// Created by roman on 01.10.2020.
//

#ifndef FLASH_BASICPLAYERGENERATOR_H
#define FLASH_BASICPLAYERGENERATOR_H

#include "../Generator.h"

namespace Generating {

    class BasicPlayerGenerator : public Generator {
    public:
        BasicPlayerGenerator(SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) override;
    };
}

#endif //FLASH_BASICPLAYERGENERATOR_H
