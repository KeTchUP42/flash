//
// Created by roman on 04.08.2020.
//

#include <fstream>

#include "FileWriter.h"
#include "../../main/general/exceptions/custom/FileCanNotBeOpened.h"

WriterUtil::FileWriter::FileWriter(const std::string &filepath) : _path(filepath) {
    this->checkPath();
}

WriterUtil::FileWriter::FileWriter(const char *filepath) : _path(filepath) {
    this->checkPath();
}

bool WriterUtil::FileWriter::write(const char *message, const std::ios::openmode &mode) const noexcept {
    std::ofstream out(_path.c_str(), mode);
    bool isOpen = out.is_open();
    if (isOpen) {
        out << message;
    }
    out.close();
    return isOpen;
}

bool WriterUtil::FileWriter::write(const std::string &message, const std::ios::openmode &mode) const noexcept {
    return write(message.c_str(), mode);
}

void WriterUtil::FileWriter::checkPath() const {
    std::ofstream out(_path, std::ios::app);
    if (!out.is_open()) {
        out.close();
        throw PreferredExceptions::FileCanNotBeOpened("File " + _path + " cannot be opened.");
    }
    out.close();
}

