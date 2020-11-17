//
// Created by roman on 10.11.2020.
//

#ifndef FLASH_PLAYERDEATHZONEGENERATOR_H
#define FLASH_PLAYERDEATHZONEGENERATOR_H

#include "../Generator.h"

namespace Creation {

    class PlayerDeathZoneGenerator : public Generator {
    public:
        PlayerDeathZoneGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) override;
    };
}

#endif //FLASH_PLAYERDEATHZONEGENERATOR_H
