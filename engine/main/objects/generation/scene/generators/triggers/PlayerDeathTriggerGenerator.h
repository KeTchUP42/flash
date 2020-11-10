//
// Created by roman on 10.11.2020.
//

#ifndef FLASH_PLAYERDEATHTRIGGERGENERATOR_H
#define FLASH_PLAYERDEATHTRIGGERGENERATOR_H

#include "../Generator.h"

namespace Generate {

    class PlayerDeathTriggerGenerator : public Generator {
    public:
        PlayerDeathTriggerGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) override;
    };
}

#endif //FLASH_PLAYERDEATHTRIGGERGENERATOR_H
