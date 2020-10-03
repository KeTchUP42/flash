//
// Created by roman on 26.09.2020.
//

#ifndef FLASH_RESULTCODES_H
#define FLASH_RESULTCODES_H

namespace Triggers {

    /**
     * @brief Enum contains triggers result codes.
     */
    enum class ResultCodes {
        OK = 0, // Nothing will happen.
        STOP,   // Code will stop Unifier's self-refresh method.
    };
}
#endif //FLASH_RESULTCODES_H
