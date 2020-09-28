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
     * @brief The base class of the LogManager class hierarchy.
     * @namespace Managers
     *
     * This class defines base LogManager interface and fields.
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
        std::shared_ptr<LoggerUtil::Logger> createLoggerForFile(const std::string &filename) const;

        /**
         * @brief Method creates Logger for some files in log directory.
         * @param filenames Some files in log directory.
         * @return New Logger.
         */
        std::shared_ptr<LoggerUtil::Logger> createLoggerForSomeFiles(const std::vector<std::string> &filenames) const;

        virtual ~LogManager() = default;

    protected:
        const std::string LOG_DIRECTORY;
    };
}
#endif //FLASH_LOGMANAGER_H
