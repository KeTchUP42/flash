//
// Created by roman on 15.11.2020.
//

#ifndef FLASH_GRAVITYZONEGENERATOR_H
#define FLASH_GRAVITYZONEGENERATOR_H

#include "../Generator.h"

namespace Creation {

    class GravityZoneGenerator : public Generator {
    public:
        explicit GravityZoneGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) override;
    };
}

#endif //FLASH_GRAVITYZONEGENERATOR_H
