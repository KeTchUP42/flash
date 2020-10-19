//
// Created by roman on 19.10.2020.
//

#ifndef FLASH_MONSTERAUDIOTRIGGERGENERATOR_H
#define FLASH_MONSTERAUDIOTRIGGERGENERATOR_H

#include "../Generator.h"

namespace Generate {

    class MonsterAudioTriggerGenerator : public Generator {
    public:
        MonsterAudioTriggerGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) override;
    };
}

#endif //FLASH_MONSTERAUDIOTRIGGERGENERATOR_H
