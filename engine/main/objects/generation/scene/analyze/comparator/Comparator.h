//
// Created by roman on 29.09.2020.
//

#ifndef FLASH_COMPARATOR_H
#define FLASH_COMPARATOR_H

#include "../../generators/Generator.h"
#include "../../../../../view/windows/screen/context-abilities/StateChangeable.h"

namespace Generating {

    /**
     * @brief Method contains generating logic.
     * @param name Generator's name.
     * @param pool Source pool.
     * @param context State changeable pointer, uses in generators constructing.
     * @return Implement generator.
     */
    Generator *compare(const std::string &name, Pools::SourcePool &pool, Screen::StateChangeable *context);
}

#endif //FLASH_COMPARATOR_H
