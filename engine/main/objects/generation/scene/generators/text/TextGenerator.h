//
// Created by roman on 12.10.2020.
//

#ifndef FLASH_TEXTGENERATOR_H
#define FLASH_TEXTGENERATOR_H

#include "../Generator.h"

namespace Generate {

    class TextGenerator : public Generator {
    public:
        TextGenerator(Pools::SourcePool &pool);

        void load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) override;
    };
}

#endif //FLASH_TEXTGENERATOR_H
