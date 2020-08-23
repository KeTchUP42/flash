//
// Created by roman on 07.08.2020.
//

#include <fstream>
#include <cstring>

#include "MultiFileWriter.h"
#include "../../main/general/exceptions/custom/FileCanNotBeOpened.h"

WriterUtil::MultiFileWriter::MultiFileWriter(const std::list<std::string> &paths) {
    this->add(paths);
}

WriterUtil::MultiFileWriter::MultiFileWriter(const std::vector<std::string> &paths) {
    this->add(paths);
}

bool WriterUtil::MultiFileWriter::write(const char *message, const std::ios::openmode &mode) const noexcept {
    bool result = true;
    for (auto &path : _paths) {
        std::ofstream out(path.c_str(), mode);
        bool isOpen = out.is_open();
        if (isOpen) {
            out << message;
        }
        out.close();
        result = result && isOpen;
    }
    return result;
}

bool WriterUtil::MultiFileWriter::write(const std::string &message, const std::ios::openmode &mode) const noexcept {
    return write(message.c_str(), mode);
}

void WriterUtil::MultiFileWriter::add(const std::list<std::string> &paths) {
    for (auto &path : paths) {
        this->add(path);
    }
}

void WriterUtil::MultiFileWriter::add(const std::vector<std::string> &paths) {
    for (auto &path : paths) {
        this->add(path);
    }
}

void WriterUtil::MultiFileWriter::add(const std::string &filepath) {
    if (this->checkPath(filepath)) {
        _paths.push_back(filepath);
    } else {
        throw PreferredExceptions::FileCanNotBeOpened(
                std::strcat(const_cast<char *>(filepath.c_str()), " cannot be opened."));
    }
}

void WriterUtil::MultiFileWriter::remove(const std::string &filepath) noexcept {
    _paths.remove(filepath);
}

bool WriterUtil::MultiFileWriter::checkPath(const std::string &filepath) const noexcept {
    std::ofstream out(filepath, std::ios::app);
    bool isOpen = out.is_open();
    out.close();
    return isOpen;
}


