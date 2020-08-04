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
        explicit Exception(const char *message = "") noexcept
                : std::exception(), _message(const_cast<char *>(message)) {}

        const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override;

        char *getMessage() const;

    protected:
        char *_message{};
    };
}

#endif //FLASH_EXCEPTION_H
