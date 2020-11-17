//
// Created by roman on 30.09.2020.
//

#ifndef FLASH_BACKGROUNDSPRITEGENERATOR_H
#define FLASH_BACKGROUNDSPRITEGENERATOR_H

#include "../Generator.h"

namespace Creation {

    class BackgroundSpriteGenerator : public Generator {
    public:
        BackgroundSpriteGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) override;
    };
}

#endif //FLASH_BACKGROUNDSPRITEGENERATOR_H
