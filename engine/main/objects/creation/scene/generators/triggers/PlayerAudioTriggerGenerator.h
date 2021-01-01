//
// Created by roman on 15.10.2020.
//

#ifndef FLASH_PLAYERAUDIOTRIGGERGENERATOR_H
#define FLASH_PLAYERAUDIOTRIGGERGENERATOR_H

#include "../Generator.h"

namespace Creation {

    class PlayerAudioTriggerGenerator : public Generator {
    public:
        explicit PlayerAudioTriggerGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) override;
    };
}

#endif //FLASH_PLAYERAUDIOTRIGGERGENERATOR_H
