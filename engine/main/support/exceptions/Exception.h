//
// Created by roman on 04.08.2020.
//

#ifndef FLASH_EXCEPTION_H
#define FLASH_EXCEPTION_H

#include <exception>
#include <string>

namespace Exceptions {

    class Exception : public std::exception {
    public:
        explicit Exception(const char *message, const int &code) noexcept
                : std::exception(), m_message(message), m_code(code) {}

        explicit Exception(const std::string &message, const int &code) noexcept
                : std::exception(), m_message(message), m_code(code) {}

        const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override;

        const std::string &getMessage() const noexcept;

        int getCode() const noexcept;

        virtual ~Exception() = default;

    protected:
        std::string m_message;
        int m_code;
    };
}

#endif //FLASH_EXCEPTION_H
