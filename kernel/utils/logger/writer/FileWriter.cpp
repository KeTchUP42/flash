//
// Created by roman on 04.08.2020.
//

#include "FileWriter.h"

LoggerUtil::FileWriter::FileWriter(const std::string &filepath) : Writer() {
    auto *out = new std::ofstream(filepath, std::ios::app);
    if (!out->is_open()) {
        out->close();
        delete out;
        throw FileIsNotOpen("The file cannot be opened.");
    }
    _out = out;
}

bool LoggerUtil::FileWriter::write(const std::string &message) const {
    if (_out->is_open()) {
        *_out << message;
        return true;
    }
    return false;
}

LoggerUtil::FileWriter::~FileWriter() {
    _out->close();
    delete _out;
}
