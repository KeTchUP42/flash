//
// Created by roman on 29.10.2020.
//

#ifndef FLASH_SINGLEPLAYERAUDIOTRIGGERGENERATOR_H
#define FLASH_SINGLEPLAYERAUDIOTRIGGERGENERATOR_H

#include "../Generator.h"

namespace Creation {

    class SinglePlayerAudioTriggerGenerator : public Generator {
    public:
        SinglePlayerAudioTriggerGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) override;
    };
}

#endif //FLASH_SINGLEPLAYERAUDIOTRIGGERGENERATOR_H
