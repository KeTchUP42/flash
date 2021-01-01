//
// Created by roman on 12.10.2020.
//

#ifndef FLASH_TEXTGENERATOR_H
#define FLASH_TEXTGENERATOR_H

#include "../Generator.h"

namespace Creation {

    class TextGenerator : public Generator {
    public:
        explicit TextGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) override;
    };
}

#endif //FLASH_TEXTGENERATOR_H
