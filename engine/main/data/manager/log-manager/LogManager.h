//
// Created by roman on 23.08.2020.
//

#ifndef FLASH_LOGMANAGER_H
#define FLASH_LOGMANAGER_H

#include <string>
#include <vector>
#include <memory>

#include "../../../../utils/logger/Logger.h"

namespace DataManagers {

    /**
     * @brief The base class of the LogManager class hierarchy.
     * @namespace DataManagers
     *
     * This class defines base LogManager interface.
     */
    class LogManager {
    public:
        explicit LogManager(const std::string &logDirectory)
                : _logDirectory(logDirectory) {}

        explicit LogManager(const char *logDirectory)
                : _logDirectory(logDirectory) {}

        /**
         * @brief Manager main factory mathod.
         * @param filename File in Log directory.
         * @return std::shared_ptr<LoggerUtil::Logger>
         */
        virtual std::shared_ptr<LoggerUtil::Logger>
        createLoggerForFile(const std::string &filename) const = 0;

        /**
         * @brief Manager main factory mathod.
         * @param filenames Files in Log directory.
         * @return std::shared_ptr<LoggerUtil::Logger>
         */
        virtual std::shared_ptr<LoggerUtil::Logger>
        createLoggerForSomeFiles(const std::vector<std::string> &filenames) const = 0;

        virtual ~LogManager() = default;

    protected:
        const std::string _logDirectory;
    };
}
#endif //FLASH_LOGMANAGER_H
