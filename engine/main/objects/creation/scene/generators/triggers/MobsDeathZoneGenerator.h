//
// Created by roman on 11.11.2020.
//

#ifndef FLASH_MOBSDEATHZONEGENERATOR_H
#define FLASH_MOBSDEATHZONEGENERATOR_H

#include "../Generator.h"

namespace Creation {

    class MobsDeathZoneGenerator : public Generator {
    public:
        explicit MobsDeathZoneGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) override;
    };
}

#endif //FLASH_MOBSDEATHZONEGENERATOR_H
