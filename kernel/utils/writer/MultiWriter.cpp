//
// Created by roman on 07.08.2020.
//

#include <fstream>
#include <cstring>

#include "../../main/general/exceptions/custom/FileCanNotBeOpened.h"
#include "MultiWriter.h"

WriterUtil::MultiWriter::MultiWriter(const std::list<std::string> &paths) {
    this->add(paths);
}

WriterUtil::MultiWriter::MultiWriter(const std::vector<std::string> &paths) {
    this->add(paths);
}

bool WriterUtil::MultiWriter::write(const char *message) const noexcept {
    bool result = true;
    for (auto &path : _paths) {
        std::ofstream out(path.c_str(), std::ios::app);
        bool isOpen = out.is_open();
        if (isOpen) {
            out << message;
        }
        out.close();
        result = result && isOpen;
    }
    return result;
}

bool WriterUtil::MultiWriter::write(const std::string &message) const noexcept {
    return write(message.c_str());
}

void WriterUtil::MultiWriter::add(const std::list<std::string> &paths) {
    for (auto &path : paths) {
        this->add(path);
    }
}

void WriterUtil::MultiWriter::add(const std::vector<std::string> &paths) {
    for (auto &path : paths) {
        this->add(path);
    }
}

void WriterUtil::MultiWriter::add(const std::string &filepath) {
    if (this->checkPath(filepath)) {
        _paths.push_back(filepath);
    } else {
        throw KernelExceptions::FileCanNotBeOpened(
                std::strcat(const_cast<char *>(filepath.c_str()), " cannot be opened."));
    }
}

void WriterUtil::MultiWriter::remove(const std::string &filepath) noexcept {
    _paths.remove(filepath);
}

bool WriterUtil::MultiWriter::checkPath(const std::string &filepath) const noexcept {
    std::ofstream out(filepath, std::ios::app);
    bool isOpen = out.is_open();
    out.close();
    return isOpen;
}


