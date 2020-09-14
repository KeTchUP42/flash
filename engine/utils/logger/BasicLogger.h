//
// Created by roman on 04.08.2020.
//

#ifndef FLASH_BASICLOGGER_H
#define FLASH_BASICLOGGER_H

#include "Logger.h"
#include "formatter/BaseLoggerFormatter.h"

namespace LoggerUtil {

    class BasicLogger : public Logger {
    public:
        explicit
        BasicLogger(WriterUtil::Writer *writer, Formatter<std::string> *formatter = new BaseLoggerFormatter())
                : Logger(writer, formatter) {}

        explicit
        BasicLogger(const std::shared_ptr<WriterUtil::Writer> &writer, const std::shared_ptr<Formatter<std::string>> &formatter =
        std::shared_ptr<Formatter<std::string>>(new BaseLoggerFormatter()))
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
#endif //FLASH_BASICLOGGER_H
