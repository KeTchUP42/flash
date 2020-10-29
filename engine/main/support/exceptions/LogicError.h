//
// Created by roman on 06.08.2020.
//

#ifndef FLASH_LOGICERROR_H
#define FLASH_LOGICERROR_H

#include "Exception.h"
#include "ExceptionCodes.h"

namespace PreferredExceptions {

    class LogicError : public Exception {
    public:
        explicit LogicError(const char *message, const int &code = ExceptionCodes::LOGIC_ERROR) noexcept
                : Exception(message, code) {}

        explicit LogicError(const std::string &message, const int &code = ExceptionCodes::LOGIC_ERROR) noexcept
                : Exception(message, code) {}
    };

}
#endif //FLASH_LOGICERROR_H
