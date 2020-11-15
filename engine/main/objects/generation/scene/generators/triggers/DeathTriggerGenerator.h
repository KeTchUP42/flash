//
// Created by roman on 15.11.2020.
//

#ifndef FLASH_DEATHTRIGGERGENERATOR_H
#define FLASH_DEATHTRIGGERGENERATOR_H

#include "../Generator.h"

namespace Generate {

    class DeathTriggerGenerator : public Generator {
    public:
        DeathTriggerGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) override;
    };
}

#endif //FLASH_DEATHTRIGGERGENERATOR_H
