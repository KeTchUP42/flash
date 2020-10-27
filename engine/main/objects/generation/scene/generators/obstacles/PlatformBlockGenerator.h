//
// Created by roman on 06.10.2020.
//

#ifndef FLASH_PLATFORMBLOCKGENERATOR_H
#define FLASH_PLATFORMBLOCKGENERATOR_H

#include "../Generator.h"

namespace Generate {

    class PlatformBlockGenerator : public Generate::Generator {
    public:
        PlatformBlockGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) override;
    };
}

#endif //FLASH_PLATFORMBLOCKGENERATOR_H
