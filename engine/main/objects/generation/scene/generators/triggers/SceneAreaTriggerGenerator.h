//
// Created by roman on 30.09.2020.
//

#ifndef FLASH_SCENEAREATRIGGERGENERATOR_H
#define FLASH_SCENEAREATRIGGERGENERATOR_H

#include "SceneTriggerGenerator.h"

namespace Generating {

    class SceneAreaTriggerGenerator : public SceneTriggerGenerator {
    public:
        explicit SceneAreaTriggerGenerator(SourcePool &pool, Screen::StateChangeable *context);

        void load(const IniProcessorUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) override;
    };
}

#endif //FLASH_SCENEAREATRIGGERGENERATOR_H
