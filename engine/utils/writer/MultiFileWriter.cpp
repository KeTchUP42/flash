//
// Created by roman on 07.08.2020.
//

#include <fstream>

#include "MultiFileWriter.h"
#include "../../main/other/exceptions/custom/FileCannotBeOpened.h"

static inline bool checkFileToOpen(const std::string &filepath);

WriterUtil::MultiFileWriter::MultiFileWriter(const std::list<std::string> &filepaths) {
    this->add(filepaths);
}

WriterUtil::MultiFileWriter::MultiFileWriter(const std::vector<std::string> &filepaths) {
    this->add(filepaths);
}

bool WriterUtil::MultiFileWriter::write(const char *message, const std::ios::openmode &mode) const noexcept {
    bool result = true;
    for (const std::string &path : m_filepaths) {
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

void WriterUtil::MultiFileWriter::add(const std::list<std::string> &filepaths) {
    for (const std::string &path : filepaths) {
        this->add(path);
    }
}

void WriterUtil::MultiFileWriter::add(const std::vector<std::string> &filepaths) {
    for (const std::string &path : filepaths) {
        this->add(path);
    }
}

void WriterUtil::MultiFileWriter::add(const std::string &filepath) {
    if (checkFileToOpen(filepath)) {
        m_filepaths.push_back(filepath);
    } else {
        throw PreferredExceptions::FileCannotBeOpened("File " + filepath + " cannot be opened.");
    }
}

void WriterUtil::MultiFileWriter::remove(const std::string &filepath) noexcept {
    m_filepaths.remove(filepath);
}

static inline bool checkFileToOpen(const std::string &filepath) {
    std::ofstream out(filepath, std::ios::app);
    bool isOpen = out.is_open();
    out.close();
    return isOpen;
}


