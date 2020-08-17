//
// Created by roman on 04.08.2020.
//

#ifndef FLASH_EXCEPTION_H
#define FLASH_EXCEPTION_H

#include <exception>
#include <string>

namespace PreferredExceptions {

    class Exception : public std::exception {
    public:
        explicit Exception(const char *message, const int &code) noexcept
                : _message(message), _code(code), std::exception() {}

        explicit Exception(const std::string &message, const int &code) noexcept
                : _message(message), _code(code), std::exception() {}

        const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override;

        const std::string getMessage() const noexcept;

        const int getCode() const noexcept;

        virtual ~Exception() noexcept = default;

    protected:
        const std::string _message;
        const int _code;
    };
}

#endif //FLASH_EXCEPTION_H
