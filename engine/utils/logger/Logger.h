//
// Created by roman on 04.08.2020.
//

#ifndef FLASH_LOGGER_H
#define FLASH_LOGGER_H

#include "../writer/Writer.h"
#include "formatter/Formatter.h"
#include "formatter/LoggerFormatter.h"

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

        explicit Logger(const std::shared_ptr<WriterUtil::Writer> &writer, const std::shared_ptr<Formatter<std::string>> &formatter)
                : m_writer(writer), m_formatter(formatter) {}

        /**
         * @brief System is unusable.
         * @return Was success?
         */
        bool emergency(const std::string &message) const noexcept;

        /**
         * @brief Action must be taken immediately.
         * @return Was success?
         */
        bool alert(const std::string &message) const noexcept;

        /**
         * @brief Critical conditions.
         * @return Was success?
         */
        bool critical(const std::string &message) const noexcept;

        /**
         * @brief Runtime errors that do not require immediate action but should typically be logged and monitored.
         * @return Was success?
         */
        bool error(const std::string &message) const noexcept;

        /**
         * @brief Exceptional occurrences that are not errors.
         * @return Was success?
         */
        bool warning(const std::string &message) const noexcept;

        /**
         * @brief Normal but significant events.
         * @return Was success?
         */
        bool notice(const std::string &message) const noexcept;

        /**
         * @brief Interesting events.
         * @return Was success?
         */
        bool info(const std::string &message) const noexcept;

        /**
         * @brief Detailed debug information.
         * @return Was success?
         */
        bool debug(const std::string &message) const noexcept;

        virtual ~Logger() noexcept = default;

    private:
        std::shared_ptr<WriterUtil::Writer> m_writer;
        std::shared_ptr<Formatter<std::string>> m_formatter;
    };
}
#endif //FLASH_LOGGER_H
