//
// Created by roman on 04.08.2020.
//

#ifndef FLASH_LOGGER_H
#define FLASH_LOGGER_H

#include <string>
#include <memory>
#include <utility>
#include "writer/Writer.h"

namespace LoggerUtil {

    class Logger {
    public:

        explicit Logger(std::shared_ptr<Writer> writer) noexcept: _writer(std::move(writer)) {}

        /**
         * System is unusable.
         */
        virtual void emergency(const std::string &message) const noexcept = 0;

        /**
         * Action must be taken immediately.
         */
        virtual void alert(const std::string &message) const noexcept = 0;

        /**
         * Critical conditions.
         */
        virtual void critical(const std::string &message) const noexcept = 0;

        /**
         * Runtime errors that do not require immediate action but should typically be logged and monitored.
         */
        virtual void error(const std::string &message) const noexcept = 0;

        /**
         * Exceptional occurrences that are not errors.
         */
        virtual void warning(const std::string &message) const noexcept = 0;

        /**
         * Normal but significant events.
         */
        virtual void notice(const std::string &message) const noexcept = 0;

        /**
         * Interesting events.
         */
        virtual void info(const std::string &message) const noexcept = 0;

        /**
         * Detailed debug information.
         */
        virtual void debug(const char *message) const noexcept = 0;


        virtual ~Logger() = default;

    protected:
        std::shared_ptr<Writer> _writer;
    };

}
#endif //FLASH_LOGGER_H
