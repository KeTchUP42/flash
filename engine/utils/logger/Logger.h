//
// Created by roman on 04.08.2020.
//

#ifndef FLASH_LOGGER_H
#define FLASH_LOGGER_H

#include "formatter/Formatter.h"
#include "../writer/Writer.h"
#include "formatter/LoggerFormatter.h"

#include <string>
#include <memory>

namespace LoggerUtil {

    /**
     * @brief The class is the simplest logger implementation.
     * @namespace LoggerUtil
     *
     * This class defines base Logger realization.
    */
    class Logger {
    public:
        explicit Logger(WriterUtil::Writer *writer, Formatter<std::string> *formatter = new LoggerFormatter())
                : m_writer(writer), m_formatter(formatter) {}

        explicit Logger(const std::shared_ptr<WriterUtil::Writer> &writer,
                        const std::shared_ptr<Formatter<std::string>> &formatter)
                : m_writer(writer), m_formatter(formatter) {}

        /**
         * System is unusable.
         */
        void emergency(const std::string &message) const noexcept;

        /**
         * Action must be taken immediately.
         */
        void alert(const std::string &message) const noexcept;

        /**
         * Critical conditions.
         */
        void critical(const std::string &message) const noexcept;

        /**
         * Runtime errors that do not require immediate action but should typically be logged and monitored.
         */
        void error(const std::string &message) const noexcept;

        /**
         * Exceptional occurrences that are not errors.
         */
        void warning(const std::string &message) const noexcept;

        /**
         * Normal but significant events.
         */
        void notice(const std::string &message) const noexcept;

        /**
         * Interesting events.
         */
        void info(const std::string &message) const noexcept;

        /**
         * Detailed debug information.
         */
        void debug(const std::string &message) const noexcept;

        virtual ~Logger() noexcept = default;

    protected:
        std::shared_ptr<WriterUtil::Writer> m_writer;
        std::shared_ptr<Formatter<std::string>> m_formatter;
    };
}
#endif //FLASH_LOGGER_H
