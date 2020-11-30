//
// Created by roman on 29.11.2020.
//

#ifndef FLASH_SHOOTINGPLAYERGENERATOR_H
#define FLASH_SHOOTINGPLAYERGENERATOR_H

#include "../Generator.h"

namespace Creation {

    class ShootingPlayerGenerator : public Generator {
    public:
        ShootingPlayerGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) override;
    };
}

#endif //FLASH_SHOOTINGPLAYERGENERATOR_H
