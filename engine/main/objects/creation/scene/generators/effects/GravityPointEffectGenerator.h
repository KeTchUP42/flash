//
// Created by roman on 08.10.2020.
//

#ifndef FLASH_GRAVITYPOINTEFFECTGENERATOR_H
#define FLASH_GRAVITYPOINTEFFECTGENERATOR_H

#include "../Generator.h"

namespace Creation {

    class GravityPointEffectGenerator : public Generator {
    public:
        explicit GravityPointEffectGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) override;
    };
}

#endif //FLASH_GRAVITYPOINTEFFECTGENERATOR_H
