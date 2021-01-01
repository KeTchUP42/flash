//
// Created by roman on 15.11.2020.
//

#ifndef FLASH_DEATHZONEGENERATOR_H
#define FLASH_DEATHZONEGENERATOR_H

#include "../Generator.h"

namespace Creation {

    class DeathZoneGenerator : public Generator {
    public:
        explicit DeathZoneGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) override;
    };
}

#endif //FLASH_DEATHZONEGENERATOR_H
