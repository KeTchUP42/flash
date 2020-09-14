//
// Created by roman on 23.08.2020.
//

#include "BasicLogManager.h"
#include "../../../../utils/logger/BasicLogger.h"
#include "../../../../utils/writer/FileWriter.h"
#include "../../../../utils/writer/MultiFileWriter.h"

std::shared_ptr<LoggerUtil::Logger>
Managers::BasicLogManager::createLoggerForFile(const std::string &filename) const {
    return std::shared_ptr<LoggerUtil::Logger>(
            new LoggerUtil::BasicLogger(new WriterUtil::FileWriter(LOG_DIRECTORY + "/" + filename)));
}

std::shared_ptr<LoggerUtil::Logger>
Managers::BasicLogManager::createLoggerForSomeFiles(const std::vector<std::string> &filenames) const {
    std::vector<std::string> filepaths = filenames;

    for (std::string &path : filepaths) {
        path = LOG_DIRECTORY + "/" + path;
    }
    return std::shared_ptr<LoggerUtil::Logger>(new LoggerUtil::BasicLogger(new WriterUtil::MultiFileWriter(filepaths)));
}
