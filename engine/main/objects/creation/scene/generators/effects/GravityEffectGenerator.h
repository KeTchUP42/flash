//
// Created by roman on 30.09.2020.
//

#ifndef FLASH_GRAVITYEFFECTGENERATOR_H
#define FLASH_GRAVITYEFFECTGENERATOR_H

#include "../Generator.h"

namespace Creation {

    class GravityEffectGenerator : public Generator {
    public:
        GravityEffectGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) override;
    };
}

#endif //FLASH_GRAVITYEFFECTGENERATOR_H
