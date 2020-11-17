//
// Created by roman on 30.09.2020.
//

#ifndef FLASH_EXPLICITPLAYERSCENETRIGGERGENERATOR_H
#define FLASH_EXPLICITPLAYERSCENETRIGGERGENERATOR_H

#include "SceneTriggerGenerator.h"

namespace Creation {

    class ExplicitPlayerSceneTriggerGenerator : public SceneTriggerGenerator {
    public:
        explicit ExplicitPlayerSceneTriggerGenerator(Pools::SourcePool &pool, View::StateChangeable *context);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) override;
    };
}

#endif //FLASH_EXPLICITPLAYERSCENETRIGGERGENERATOR_H
