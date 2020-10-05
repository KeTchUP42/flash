//
// Created by roman on 05.10.2020.
//

#ifndef FLASH_ABSCISSAPLAYERSCENETRIGGERGENERATOR_H
#define FLASH_ABSCISSAPLAYERSCENETRIGGERGENERATOR_H

#include "SceneTriggerGenerator.h"

namespace Generate {

    class AbscissaPlayerSceneTriggerGenerator : public SceneTriggerGenerator {
    public:
        explicit AbscissaPlayerSceneTriggerGenerator(Pools::SourcePool &pool, Screen::StateChangeable *context);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) override;
    };
}

#endif //FLASH_ABSCISSAPLAYERSCENETRIGGERGENERATOR_H
