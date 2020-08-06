//
// Created by roman on 06.08.2020.
//

#ifndef FLASH_LOGICERROR_H
#define FLASH_LOGICERROR_H

#include "Exception.h"

namespace KernelExceptions {

    class LogicError : public Exception {
    public:
        explicit
        LogicError(const char *message) : Exception(message) {}

        explicit
        LogicError(const std::string &message) : Exception(message) {}
    };

}
#endif //FLASH_LOGICERROR_H
