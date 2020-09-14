//
// Created by roman on 06.08.2020.
//

#ifndef FLASH_INVALIDARGUMENT_H
#define FLASH_INVALIDARGUMENT_H

#include "LogicError.h"

namespace PreferredExceptions {

    class InvalidArgument : public LogicError {
    public:
        explicit InvalidArgument(const char *message, const int &code = ExceptionCodes::INVALID_ARGUMENT)
                : LogicError(message, code) {}

        explicit InvalidArgument(const std::string &message, const int &code = ExceptionCodes::INVALID_ARGUMENT)
                : LogicError(message, code) {}
    };

}
#endif //FLASH_INVALIDARGUMENT_H
