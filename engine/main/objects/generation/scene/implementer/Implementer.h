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
     * @param name Generator name.
     * @param pool Source pool.
     * @param context State changeable pointer, uses in generators constructing.
     * @return Implement generator.
     */
    Generator *implement(const std::string &name, SourcePool &pool, Screen::StateChangeable *context);
}

#endif //FLASH_IMPLEMENTER_H
