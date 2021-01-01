//
// Created by roman on 05.10.2020.
//

#ifndef FLASH_ABSCISSAPLAYERSCENETRIGGERGENERATOR_H
#define FLASH_ABSCISSAPLAYERSCENETRIGGERGENERATOR_H

#include "SceneTriggerGenerator.h"

namespace Creation {

    class AbscissaPlayerSceneTriggerGenerator : public SceneTriggerGenerator {
    public:
        AbscissaPlayerSceneTriggerGenerator(Pools::SourcePool &pool, View::StateChangeable *context);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) override;
    };
}

#endif //FLASH_ABSCISSAPLAYERSCENETRIGGERGENERATOR_H
