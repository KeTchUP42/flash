//
// Created by roman on 04.08.2020.
//

#ifndef FLASH_EXCEPTION_H
#define FLASH_EXCEPTION_H

#include <exception>
#include <ostream>

namespace KernelExceptions {

    class Exception : public std::exception {
    public:
        explicit
        Exception(const char *message) noexcept: _message(message), std::exception() {}

        const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override;

        [[maybe_unused]] const char *getMessage() const noexcept;

    protected:
        const char *_message;
    };
}

#endif //FLASH_EXCEPTION_H
