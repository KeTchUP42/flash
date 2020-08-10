//
// Created by roman on 04.08.2020.
//

#include <fstream>
#include <cstring>

#include "FileWriter.h"
#include "../../main/general/exceptions/custom/FileCanNotBeOpened.h"

WriterUtil::FileWriter::FileWriter(const std::string &filepath) : _path(filepath) {
    this->checkPath();
}

WriterUtil::FileWriter::FileWriter(const char *filepath) : _path(filepath) {
    this->checkPath();
}

bool WriterUtil::FileWriter::write(const char *message) const noexcept {
    std::ofstream out(_path.c_str(), std::ios::app);
    bool isOpen = out.is_open();
    if (isOpen) {
        out << message;
    }
    out.close();
    return isOpen;
}

bool WriterUtil::FileWriter::write(const std::string &message) const noexcept {
    return write(message.c_str());
}

void WriterUtil::FileWriter::checkPath() const {
    std::ofstream out(_path, std::ios::app);
    if (!out.is_open()) {
        out.close();
        throw KernelExceptions::FileCanNotBeOpened(
                std::strcat(const_cast<char *>(_path.c_str()), " cannot be opened."));
    }
    out.close();
}

