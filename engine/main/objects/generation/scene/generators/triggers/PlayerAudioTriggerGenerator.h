//
// Created by roman on 15.10.2020.
//

#ifndef FLASH_PLAYERAUDIOTRIGGERGENERATOR_H
#define FLASH_PLAYERAUDIOTRIGGERGENERATOR_H

#include "../Generator.h"

namespace Generate {

    class PlayerAudioTriggerGenerator : public Generator {
    public:
        PlayerAudioTriggerGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) override;
    };
}

#endif //FLASH_PLAYERAUDIOTRIGGERGENERATOR_H
