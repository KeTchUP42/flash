//
// Created by roman on 21.11.2020.
//

#ifndef FLASH_INICREATOR_H
#define FLASH_INICREATOR_H

#include "Creator.h"

namespace IniUtil {

    class IniCreator : public Creator {
    public:
        std::string create(const Analyzer::IniData &data) const override;
    };
}

#endif //FLASH_INICREATOR_H
