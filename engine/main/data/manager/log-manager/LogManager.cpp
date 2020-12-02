//
// Created by roman on 27.09.2020.
//

#include "LogManager.h"
#include "../../../../utils/writer/FileWriter.h"
#include "../../../../utils/writer/MultiFileWriter.h"

std::shared_ptr<LoggerUtil::Logger>
Managers::LogManager::createLogger(const std::string &filename) const {
    return std::make_shared<LoggerUtil::Logger>(new WriterUtil::FileWriter(LOG_DIRECTORY + "/" + filename));
}

std::shared_ptr<LoggerUtil::Logger>
Managers::LogManager::createLogger(const std::vector<std::string> &filenames) const {
    std::vector<std::string> files = filenames;

    for (std::string &path : files) {
        path = LOG_DIRECTORY + "/" + path;
    }
    return std::make_shared<LoggerUtil::Logger>(new WriterUtil::MultiFileWriter(files));
}