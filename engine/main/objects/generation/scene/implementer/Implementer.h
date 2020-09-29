//
// Created by roman on 29.09.2020.
//

#ifndef FLASH_IMPLEMENTER_H
#define FLASH_IMPLEMENTER_H

#include "../generators/Generator.h"
#include "../../../../view/windows/screen/context-abilities/StateChangeable.h"

namespace Generating {

    /**
     * @brief Method contains generating logic.
     * @param alias Generator alias.
     * @param pool Source pool.
     * @param context State changeable pointer, uses in generators constructing.
     * @return Implement generator.
     */
    Generator *implement(const std::string &alias, SourcePool &pool, Screen::StateChangeable *context) noexcept;
}

#endif //FLASH_IMPLEMENTER_H
