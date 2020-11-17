//
// Created by roman on 06.10.2020.
//

#ifndef FLASH_DULLINVISIBLEBLOCKGENARATOR_H
#define FLASH_DULLINVISIBLEBLOCKGENARATOR_H

#include "../Generator.h"

namespace Creation {

    class DullInvisibleBlockGenarator : public Creation::Generator {
    public:
        DullInvisibleBlockGenarator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) override;
    };
}

#endif //FLASH_DULLINVISIBLEBLOCKGENARATOR_H
