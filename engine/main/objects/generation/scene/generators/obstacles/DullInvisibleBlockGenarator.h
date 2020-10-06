//
// Created by roman on 06.10.2020.
//

#ifndef FLASH_DULLINVISIBLEBLOCKGENARATOR_H
#define FLASH_DULLINVISIBLEBLOCKGENARATOR_H

#include "../Generator.h"

namespace Generate {

    class DullInvisibleBlockGenarator : public Generate::Generator {
    public:
        DullInvisibleBlockGenarator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) override;
    };
}

#endif //FLASH_DULLINVISIBLEBLOCKGENARATOR_H
