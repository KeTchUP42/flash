//
// Created by roman on 11.11.2020.
//

#ifndef FLASH_MOBSDEATHTRIGGERGENERATOR_H
#define FLASH_MOBSDEATHTRIGGERGENERATOR_H

#include "../Generator.h"

namespace Generate {

    class MobsDeathTriggerGenerator : public Generator {
    public:
        MobsDeathTriggerGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) override;
    };
}

#endif //FLASH_MOBSDEATHTRIGGERGENERATOR_H
