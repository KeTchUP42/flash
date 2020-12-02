//
// Created by roman on 04.08.2020.
//

#include <fstream>

#include "FileWriter.h"
#include "../../main/support/exceptions/custom/FileCannotBeOpened.h"

WriterUtil::FileWriter::FileWriter(const std::string &filename) : m_filename(filename) {
    std::ofstream out(filename, std::ios::app);
    if (!out.is_open()) {
        throw Exceptions::FileCannotBeOpened("File " + filename + " cannot be opened.");
    }
}

bool WriterUtil::FileWriter::write(const char *message, const std::ios::openmode &mode) const {
    std::ofstream out(m_filename.c_str(), mode);
    bool isOpen = out.is_open();
    if (isOpen) {
        out << message;
    }
    return isOpen;
}

bool WriterUtil::FileWriter::write(const std::string &message, const std::ios::openmode &mode) const {
    return write(message.c_str(), mode);
}
