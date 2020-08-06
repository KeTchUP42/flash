//
// Created by roman on 04.08.2020.
//

#ifndef FLASH_RUNTIMEEXCEPTION_H
#define FLASH_RUNTIMEEXCEPTION_H

#include "Exception.h"

namespace KernelExceptions {

    class RuntimeException : public KernelExceptions::Exception {
    public:
        explicit
        RuntimeException(const char *message) noexcept: Exception(message) {}

        explicit
        RuntimeException(const std::string &message) noexcept: Exception(message) {}
    };

}
#endif //FLASH_RUNTIMEEXCEPTION_H
