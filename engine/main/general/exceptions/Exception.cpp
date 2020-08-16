//
// Created by roman on 04.08.2020.
//

#include "Exception.h"

const char *PreferredExceptions::Exception::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT {
    return _message.c_str();
}

const std::string PreferredExceptions::Exception::getMessage() const noexcept {
    return _message;
}

const int PreferredExceptions::Exception::getCode() const noexcept {
    return _code;
}
