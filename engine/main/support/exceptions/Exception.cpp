//
// Created by roman on 04.08.2020.
//

#include "Exception.h"

const char *Exceptions::Exception::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT {
    return m_message.c_str();
}

const std::string &Exceptions::Exception::getMessage() const noexcept {
    return m_message;
}

int Exceptions::Exception::getCode() const noexcept {
    return m_code;
}
