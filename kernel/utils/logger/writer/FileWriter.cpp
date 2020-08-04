//
// Created by roman on 04.08.2020.
//

#include "FileWriter.h"
#include <fstream>

LoggerUtil::FileWriter::FileWriter(const std::string &filepath) : _path(filepath.c_str()), Writer() {
    checkFile();
}

LoggerUtil::FileWriter::FileWriter(const char *filepath) : _path(filepath), Writer() {
    checkFile();
}

bool LoggerUtil::FileWriter::write(const char *message) const noexcept {
    std::ofstream out(_path, std::ios::app);
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

void LoggerUtil::FileWriter::checkFile() const {
    std::ofstream out(_path, std::ios::app);
    if (!out.is_open()) {
        out.close();
        throw FileIsNotOpen("The file cannot be opened.");
    }
    out.close();
}

LoggerUtil::FileWriter::~FileWriter() {
    delete _path;
}
