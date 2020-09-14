//
// Created by roman on 23.08.2020.
//

#ifndef FLASH_BASICLOGMANAGER_H
#define FLASH_BASICLOGMANAGER_H

#include "LogManager.h"

namespace Managers {

    class BasicLogManager : public LogManager {
    public:
        explicit BasicLogManager(const std::string &logDirectory)
                : LogManager(logDirectory) {}

        explicit BasicLogManager(const char *logDirectory)
                : LogManager(logDirectory) {}

        std::shared_ptr<LoggerUtil::Logger> createLoggerForFile(const std::string &filename) const override;

        std::shared_ptr<LoggerUtil::Logger>
        createLoggerForSomeFiles(const std::vector<std::string> &filenames) const override;
    };
}

#endif //FLASH_BASICLOGMANAGER_H
