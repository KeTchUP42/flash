//
// Created by roman on 04.08.2020.
//

#include "Exception.h"

const char *KernelExceptions::Exception::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT {
    return _message;
}

const char *KernelExceptions::Exception::getMessage() const noexcept {
    return _message;
}

KernelExceptions::Exception::~Exception() {
    delete[] _message;
}
