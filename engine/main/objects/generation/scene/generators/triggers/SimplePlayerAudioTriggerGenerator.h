//
// Created by roman on 15.10.2020.
//

#ifndef FLASH_SIMPLEPLAYERAUDIOTRIGGERGENERATOR_H
#define FLASH_SIMPLEPLAYERAUDIOTRIGGERGENERATOR_H

#include "../Generator.h"

namespace Generate {

    class SimplePlayerAudioTriggerGenerator : public Generator {
    public:
        SimplePlayerAudioTriggerGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) override;
    };
}

#endif //FLASH_SIMPLEPLAYERAUDIOTRIGGERGENERATOR_H
