//
// Created by roman on 23.08.2020.
//

#ifndef FLASH_BASELOGMANAGER_H
#define FLASH_BASELOGMANAGER_H

#include "LogManager.h"

namespace Managers {

    class BaseLogManager : public LogManager {
    public:
        explicit BaseLogManager(const std::string &logDirectory)
                : LogManager(logDirectory) {}

        explicit BaseLogManager(const char *logDirectory)
                : LogManager(logDirectory) {}

        std::shared_ptr<LoggerUtil::Logger> createLoggerForFile(const std::string &filename) const override;

        std::shared_ptr<LoggerUtil::Logger>
        createLoggerForSomeFiles(const std::vector<std::string> &filenames) const override;
    };
}

#endif //FLASH_BASELOGMANAGER_H
