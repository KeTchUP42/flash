//
// Created by roman on 04.08.2020.
//

#include <fstream>

#include "FileWriter.h"
#include "../../main/other/exceptions/custom/FileCannotBeOpened.h"

static inline void checkFileToOpen(const std::string &filepath);

WriterUtil::FileWriter::FileWriter(const std::string &filepath) : m_filepath(filepath) {
    checkFileToOpen(filepath);
}

WriterUtil::FileWriter::FileWriter(const char *filepath) : m_filepath(filepath) {
    checkFileToOpen(filepath);
}

bool WriterUtil::FileWriter::write(const char *message, const std::ios::openmode &mode) const noexcept {
    std::ofstream out(m_filepath.c_str(), mode);
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

static inline void checkFileToOpen(const std::string &filepath) {
    std::ofstream out(filepath, std::ios::app);
    if (!out.is_open()) {
        out.close();
        throw PreferredExceptions::FileCannotBeOpened("File " + filepath + " cannot be opened.");
    }
    out.close();
}

