//
// Created by roman on 23.08.2020.
//

#ifndef FLASH_LOGMANAGER_H
#define FLASH_LOGMANAGER_H

#include <string>
#include <vector>
#include <memory>

#include "../../../../utils/logger/Logger.h"

namespace Managers {

    /**
     * @brief The class provides a convenient way to create loggers.
     * @namespace Managers
     *
     * This class defines LogManager interface and realization.
     */
    class LogManager {
    public:
        explicit LogManager(const std::string &logDirectory)
                : LOG_DIRECTORY(logDirectory) {}

        explicit LogManager(const char *logDirectory)
                : LOG_DIRECTORY(logDirectory) {}

        /**
         * @brief Method creates Logger for file in log directory.
         * @param filename File in log directory.
         * @return New Logger.
         */
        std::shared_ptr<LoggerUtil::Logger> createLogger(const std::string &filename) const;

        /**
         * @brief Method creates Logger for some files in log directory.
         * @param filenames Some files in log directory.
         * @return New Logger.
         */
        std::shared_ptr<LoggerUtil::Logger> createLogger(const std::vector<std::string> &filenames) const;

        virtual ~LogManager() = default;

    private:
        const std::string LOG_DIRECTORY;
    };
}
#endif //FLASH_LOGMANAGER_H
