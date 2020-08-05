//
// Created by roman on 04.08.2020.
//

#include "Exception.h"

const char *KernelExceptions::Exception::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT {
    return _message;
}

[[maybe_unused]] const char *KernelExceptions::Exception::getMessage() const noexcept {
    return _message;
}
