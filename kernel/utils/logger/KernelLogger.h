//
// Created by roman on 04.08.2020.
//

#ifndef FLASH_KERNELLOGGER_H
#define FLASH_KERNELLOGGER_H

#include "Logger.h"

namespace LoggerUtil {

    class KernelLogger : public Logger {
    public:
        explicit
        KernelLogger(Writer *writer) : Logger(writer) {}

        void emergency(const std::string &) const noexcept override;

        void alert(const std::string &) const noexcept override;

        void critical(const std::string &) const noexcept override;

        void error(const std::string &) const noexcept override;

        void warning(const std::string &) const noexcept override;

        void notice(const std::string &) const noexcept override;

        void info(const std::string &) const noexcept override;

        void debug(const std::string &) const noexcept override;

    protected:
        std::string dateTimeNow() const noexcept;
    };
}
#endif //FLASH_KERNELLOGGER_H
