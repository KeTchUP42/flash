//
// Created by roman on 12.11.2020.
//

#ifndef FLASH_GRAVITYPLAYERZONEGENERATOR_H
#define FLASH_GRAVITYPLAYERZONEGENERATOR_H

#include "../Generator.h"

namespace Creation {

    class GravityPlayerZoneGenerator : public Generator {
    public:
        explicit GravityPlayerZoneGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) override;
    };
}

#endif //FLASH_GRAVITYPLAYERZONEGENERATOR_H
