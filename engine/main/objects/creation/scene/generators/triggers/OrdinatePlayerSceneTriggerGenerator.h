//
// Created by roman on 05.10.2020.
//

#ifndef FLASH_ORDINATEPLAYERSCENETRIGGERGENERATOR_H
#define FLASH_ORDINATEPLAYERSCENETRIGGERGENERATOR_H

#include "SceneTriggerGenerator.h"

namespace Creation {

    class OrdinatePlayerSceneTriggerGenerator : public SceneTriggerGenerator {
    public:
        explicit OrdinatePlayerSceneTriggerGenerator(Pools::SourcePool &pool, View::StateChangeable *context);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) override;
    };
}

#endif //FLASH_ORDINATEPLAYERSCENETRIGGERGENERATOR_H
