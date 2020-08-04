//
// Created by roman on 04.08.2020.
//

#ifndef FLASH_KERNELRUNTIMEEXCEPTION_H
#define FLASH_KERNELRUNTIMEEXCEPTION_H

#include <exception>
#include <utility>
#include "Exception.h"

namespace KernelExceptions {

    class KernelRuntimeException : public KernelExceptions::Exception {
    public:
        explicit KernelRuntimeException(const char *message) noexcept: Exception(message) {}
    };

}
#endif //FLASH_KERNELRUNTIMEEXCEPTION_H
