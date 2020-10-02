//
// Created by roman on 29.09.2020.
//

#ifndef FLASH_DULLBLOCKGENERATOR_H
#define FLASH_DULLBLOCKGENERATOR_H

#include "../Generator.h"

namespace Generating {

    class DullBlockGenerator : public Generating::Generator {
    public:
        DullBlockGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) override;
    };
}

#endif //FLASH_DULLBLOCKGENERATOR_H
