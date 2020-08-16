//
// Created by roman on 10.08.2020.
//
#include <fstream>
#include <cstring>
#include <iterator>

#include "FileReader.h"
#include "../../main/general/exceptions/custom/FileCanNotBeOpened.h"


ReaderUtil::FileReader::FileReader(const std::string &filepath) : _path(filepath) {
    this->checkPath(_path);
}

ReaderUtil::FileReader::FileReader(const char *filepath) : _path(filepath) {
    this->checkPath(_path);
}

std::string ReaderUtil::FileReader::read() const noexcept {
    std::string result;
    std::ifstream in(_path.c_str());
    if (in.is_open()) {
        in >> std::noskipws;
        std::copy(std::istream_iterator<char>(in), std::istream_iterator<char>(), std::back_inserter(result));
    }
    in.close();
    return result;
}

std::vector<std::string> ReaderUtil::FileReader::readlines() const noexcept {
    std::vector<std::string> result;
    std::ifstream in(_path.c_str());
    if (in.is_open()) {
        std::string line;
        while (std::getline(in, line)) {
            result.push_back(std::move(line));
        }
    }
    in.close();
    return result;
}

void ReaderUtil::FileReader::checkPath(const std::string &path) const {
    std::ifstream in(path);
    if (!in.is_open()) {
        in.close();
        throw PreferredExceptions::FileCanNotBeOpened(
                std::strcat(const_cast<char *>(_path.c_str()), " cannot be opened."));
    }
    in.close();
}