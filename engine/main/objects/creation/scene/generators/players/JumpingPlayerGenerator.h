//
// Created by roman on 01.10.2020.
//

#ifndef FLASH_JUMPINGPLAYERGENERATOR_H
#define FLASH_JUMPINGPLAYERGENERATOR_H

#include "../Generator.h"

namespace Creation {

    class JumpingPlayerGenerator : public Generator {
    public:
        JumpingPlayerGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) override;
    };
}

#endif //FLASH_JUMPINGPLAYERGENERATOR_H
