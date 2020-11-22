//
// Created by roman on 22.11.2020.
//

#ifndef FLASH_SLIMEGENERATOR_H
#define FLASH_SLIMEGENERATOR_H

#include "../Generator.h"

namespace Creation {

    class SlimeGenerator : public Generator {
    public:
        SlimeGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) override;
    };
}

#endif //FLASH_SLIMEGENERATOR_H
