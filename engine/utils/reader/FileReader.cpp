//
// Created by roman on 10.08.2020.
//
#include <fstream>
#include <iterator>

#include "FileReader.h"
#include "../../main/other/exceptions/custom/FileCannotBeOpened.h"

static inline void checkFileToOpen(const std::string &path);

ReaderUtil::FileReader::FileReader(const std::string &filepath) : m_path(filepath) {
    checkFileToOpen(filepath);
}

ReaderUtil::FileReader::FileReader(const char *filepath) : m_path(filepath) {
    checkFileToOpen(filepath);
}

std::string ReaderUtil::FileReader::read() const noexcept {
    std::string result;
    std::ifstream in(m_path.c_str());
    if (in.is_open()) {
        in >> std::noskipws;
        std::copy(std::istream_iterator<char>(in), std::istream_iterator<char>(), std::back_inserter(result));
    }
    in.close();
    return result;
}

std::vector<std::string> ReaderUtil::FileReader::readlines() const noexcept {
    std::vector<std::string> result;
    std::ifstream in(m_path.c_str());
    if (in.is_open()) {
        std::string line;
        while (std::getline(in, line)) {
            result.push_back(std::move(line));
        }
    }
    in.close();
    return result;
}

static inline void checkFileToOpen(const std::string &path) {
    std::ifstream in(path);
    if (!in.is_open()) {
        in.close();
        throw PreferredExceptions::FileCannotBeOpened("File " + path + " cannot be opened.");
    }
    in.close();
}