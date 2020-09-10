//
// Created by roman on 23.08.2020.
//

#include "BaseLogManager.h"
#include "../../../../utils/logger/BaseLogger.h"
#include "../../../../utils/writer/FileWriter.h"
#include "../../../../utils/writer/MultiFileWriter.h"

std::shared_ptr<LoggerUtil::Logger>
Managers::BaseLogManager::createLoggerForFile(const std::string &filename) const {
    return std::shared_ptr<LoggerUtil::Logger>(
            new LoggerUtil::BaseLogger(new WriterUtil::FileWriter(_logs + "/" + filename)));
}

std::shared_ptr<LoggerUtil::Logger>
Managers::BaseLogManager::createLoggerForSomeFiles(const std::vector<std::string> &filenames) const {
    std::vector<std::string> paths = filenames;

    for (std::string &path : paths) {
        path = _logs + "/" + path;
    }
    return std::shared_ptr<LoggerUtil::Logger>(new LoggerUtil::BaseLogger(new WriterUtil::MultiFileWriter(paths)));
}
