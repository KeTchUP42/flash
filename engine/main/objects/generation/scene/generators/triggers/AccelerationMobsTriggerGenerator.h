//
// Created by roman on 12.11.2020.
//

#ifndef FLASH_ACCELERATIONMOBSTRIGGERGENERATOR_H
#define FLASH_ACCELERATIONMOBSTRIGGERGENERATOR_H

#include "../Generator.h"

namespace Generate {

    class AccelerationMobsTriggerGenerator : public Generator {
    public:
        AccelerationMobsTriggerGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) override;
    };
}

#endif //FLASH_ACCELERATIONMOBSTRIGGERGENERATOR_H
