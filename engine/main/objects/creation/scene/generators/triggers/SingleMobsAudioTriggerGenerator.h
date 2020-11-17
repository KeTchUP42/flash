//
// Created by roman on 29.10.2020.
//

#ifndef FLASH_SINGLEMOBSAUDIOTRIGGERGENERATOR_H
#define FLASH_SINGLEMOBSAUDIOTRIGGERGENERATOR_H

#include "../Generator.h"

namespace Creation {

    class SingleMobsAudioTriggerGenerator : public Generator {
    public:
        SingleMobsAudioTriggerGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) override;
    };
}

#endif //FLASH_SINGLEMOBSAUDIOTRIGGERGENERATOR_H
