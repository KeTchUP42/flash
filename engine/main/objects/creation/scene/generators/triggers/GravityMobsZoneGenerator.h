//
// Created by roman on 12.11.2020.
//

#ifndef FLASH_GRAVITYMOBSZONEGENERATOR_H
#define FLASH_GRAVITYMOBSZONEGENERATOR_H

#include "../Generator.h"

namespace Creation {

    class GravityMobsZoneGenerator : public Generator {
    public:
        GravityMobsZoneGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) override;
    };
}

#endif //FLASH_GRAVITYMOBSZONEGENERATOR_H
