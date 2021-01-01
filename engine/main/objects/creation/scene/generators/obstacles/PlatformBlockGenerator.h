//
// Created by roman on 06.10.2020.
//

#ifndef FLASH_PLATFORMBLOCKGENERATOR_H
#define FLASH_PLATFORMBLOCKGENERATOR_H

#include "../Generator.h"

namespace Creation {

    class PlatformBlockGenerator : public Creation::Generator {
    public:
        explicit PlatformBlockGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) override;
    };
}

#endif //FLASH_PLATFORMBLOCKGENERATOR_H
