//
// Created by roman on 04.08.2020.
//

#ifndef FLASH_LOGGER_H
#define FLASH_LOGGER_H

#include "formatter/Formatter.h"
#include "../writer/Writer.h"

#include <string>
#include <memory>

namespace LoggerUtil {

    /**
     * @brief The base class of the Logger class hierarchy.
     * @namespace LoggerUtil
     *
     * This class defines base Logger interface and fields.
    */
    class Logger {
    public:

        explicit Logger(WriterUtil::Writer *writer, Formatter<std::string> *formatter) : _writer(writer), _formatter(formatter) {}

        explicit Logger(const std::shared_ptr<WriterUtil::Writer> &writer,
                        const std::shared_ptr<Formatter<std::string>> &formatter)
                : _writer(writer), _formatter(formatter) {}

        Logger &operator=(const Logger &) = delete;

        /**
         * System is unusable.
         */
        virtual void emergency(const std::string &) const noexcept = 0;

        /**
         * Action must be taken immediately.
         */
        virtual void alert(const std::string &) const noexcept = 0;

        /**
         * Critical conditions.
         */
        virtual void critical(const std::string &) const noexcept = 0;

        /**
         * Runtime errors that do not require immediate action but should typically be logged and monitored.
         */
        virtual void error(const std::string &) const noexcept = 0;

        /**
         * Exceptional occurrences that are not errors.
         */
        virtual void warning(const std::string &) const noexcept = 0;

        /**
         * Normal but significant events.
         */
        virtual void notice(const std::string &) const noexcept = 0;

        /**
         * Interesting events.
         */
        virtual void info(const std::string &) const noexcept = 0;

        /**
         * Detailed debug information.
         */
        virtual void debug(const std::string &) const noexcept = 0;

        virtual ~Logger() noexcept = default;

    protected:
        std::shared_ptr<WriterUtil::Writer> _writer;
        std::shared_ptr<Formatter<std::string>> _formatter;
    };

}
#endif //FLASH_LOGGER_H
