//
// Created by roman on 29.09.2020.
//

#ifndef FLASH_GENERATORSELECT_H
#define FLASH_GENERATORSELECT_H

#include "../generators/Generator.h"
#include "../../../../view/windows/screen/context-abilities/StateChangeable.h"

namespace Generate {

    /**
     * @brief Function contains selecting and creating logic.
     * @param name Generator's name.
     * @param pool Source pool.
     * @param context State changeable pointer, uses in generators constructing.
     * @return Implement generator.
     */
    Generator *selectGenerator(const std::string &name, Pools::SourcePool &pool, Screen::StateChangeable *context);
}

#endif //FLASH_GENERATORSELECT_H
