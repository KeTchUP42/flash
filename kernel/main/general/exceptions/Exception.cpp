//
// Created by roman on 04.08.2020.
//

#include "Exception.h"
#include <cstring>

const char *KernelExceptions::Exception::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT {
    return std::strcat(_message, exception::what());
}

char *KernelExceptions::Exception::getMessage() const {
    return _message;
}
