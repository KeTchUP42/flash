//
// Created by roman on 19.10.2020.
//

#ifndef FLASH_MOBSAUDIOTRIGGERGENERATOR_H
#define FLASH_MOBSAUDIOTRIGGERGENERATOR_H

#include "../Generator.h"

namespace Generate {

    class MobsAudioTriggerGenerator : public Generator {
    public:
        MobsAudioTriggerGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) override;
    };
}

#endif //FLASH_MOBSAUDIOTRIGGERGENERATOR_H
