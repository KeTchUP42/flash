//
// Created by roman on 04.10.2020.
//

#ifndef FLASH_FRONTSPRITEGENERATOR_H
#define FLASH_FRONTSPRITEGENERATOR_H

#include "../Generator.h"

namespace Creation {

    class FrontSpriteGenerator : public Generator {
    public:
        FrontSpriteGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) override;
    };
}

#endif //FLASH_FRONTSPRITEGENERATOR_H
