//
// Created by roman on 17.10.2020.
//

#ifndef FLASH_BACKAUDIOEFFECTGENERATOR_H
#define FLASH_BACKAUDIOEFFECTGENERATOR_H

#include "../Generator.h"

namespace Creation {

    class BackAudioEffectGenerator : public Generator {
    public:
        BackAudioEffectGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) override;
    };
}

#endif //FLASH_BACKAUDIOEFFECTGENERATOR_H
