//
// Created by roman on 12.11.2020.
//

#ifndef FLASH_ACCELERATIONPLAYERTRIGGERGENERATOR_H
#define FLASH_ACCELERATIONPLAYERTRIGGERGENERATOR_H

#include "../Generator.h"

namespace Generate {

    class AccelerationPlayerTriggerGenerator : public Generator {
    public:
        AccelerationPlayerTriggerGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) override;
    };
}

#endif //FLASH_ACCELERATIONPLAYERTRIGGERGENERATOR_H
