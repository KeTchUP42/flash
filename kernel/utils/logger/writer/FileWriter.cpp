//
// Created by roman on 04.08.2020.
//

#include "FileWriter.h"
#include <fstream>
#include <cstring>

LoggerUtil::FileWriter::FileWriter(const std::string &filepath) : _path(filepath), Writer() {
    this->checkPath();
}

LoggerUtil::FileWriter::FileWriter(const char *filepath) : _path(std::string(filepath)), Writer() {
    this->checkPath();
}

bool LoggerUtil::FileWriter::write(const char *message) const noexcept {
    std::ofstream out(_path.c_str(), std::ios::app);
    bool isOpen = out.is_open();
    if (isOpen) {
        out << message;
    }
    out.close();
    return isOpen;
}

bool LoggerUtil::FileWriter::write(const std::string &message) const noexcept {
    return write(message.c_str());
}

void LoggerUtil::FileWriter::checkPath() const {
    std::ofstream out(_path, std::ios::app);
    if (!out.is_open()) {
        out.close();
        throw FileCanNotBeOpened(std::strcat(const_cast<char *>(_path.c_str()), " cannot be opened."));
    }
    out.close();
}

