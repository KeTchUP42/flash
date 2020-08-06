//
// Created by roman on 06.08.2020.
//

#ifndef FLASH_INVALIDARGUMENT_H
#define FLASH_INVALIDARGUMENT_H

#include "LogicError.h"

namespace KernelExceptions {

    class InvalidArgument : public LogicError {
    public:
        explicit
        InvalidArgument(const char *message) : LogicError(message) {}

        explicit
        InvalidArgument(const std::string &message) : LogicError(message) {}
    };

}
#endif //FLASH_INVALIDARGUMENT_H
