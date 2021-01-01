//
// Created by roman on 04.10.2020.
//

#ifndef FLASH_BACKSPRITEGENERATOR_H
#define FLASH_BACKSPRITEGENERATOR_H

#include "../Generator.h"

namespace Creation {

    class BackSpriteGenerator : public Generator {
    public:
        explicit BackSpriteGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) override;
    };
}

#endif //FLASH_BACKSPRITEGENERATOR_H
