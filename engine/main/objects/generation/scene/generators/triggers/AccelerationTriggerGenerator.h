//
// Created by roman on 15.11.2020.
//

#ifndef FLASH_ACCELERATIONTRIGGERGENERATOR_H
#define FLASH_ACCELERATIONTRIGGERGENERATOR_H

#include "../Generator.h"

namespace Generate {

    class AccelerationTriggerGenerator : public Generator {
    public:
        AccelerationTriggerGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) override;
    };
}

#endif //FLASH_ACCELERATIONTRIGGERGENERATOR_H
