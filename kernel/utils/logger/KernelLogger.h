//
// Created by roman on 04.08.2020.
//

#ifndef FLASH_KERNELLOGGER_H
#define FLASH_KERNELLOGGER_H

#include "Logger.h"
#include "formatter/KernelLoggerFormatter.h"

namespace LoggerUtil {

    class KernelLogger : public Logger {
    public:
        explicit
        KernelLogger(Writer *writer, Formatter<std::string> *formatter = new KernelLoggerFormatter())
                : Logger(writer, formatter) {}

        explicit
        KernelLogger(const std::shared_ptr<Writer> &writer,
                     const std::shared_ptr<Formatter<std::string>> &formatter =
                     std::shared_ptr<Formatter<std::string>>(new KernelLoggerFormatter()))
                : Logger(writer, formatter) {}

        void emergency(const std::string &message) const noexcept override;

        void alert(const std::string &message) const noexcept override;

        void critical(const std::string &message) const noexcept override;

        void error(const std::string &message) const noexcept override;

        void warning(const std::string &message) const noexcept override;

        void notice(const std::string &message) const noexcept override;

        void info(const std::string &message) const noexcept override;

        void debug(const std::string &message) const noexcept override;
    };
}
#endif //FLASH_KERNELLOGGER_H
