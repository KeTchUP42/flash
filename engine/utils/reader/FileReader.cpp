//
// Created by roman on 10.08.2020.
//
#include <fstream>
#include <iterator>

#include "FileReader.h"
#include "../../main/support/exceptions/custom/FileCannotBeOpened.h"

ReaderUtil::FileReader::FileReader(const std::string &filepath) : m_filepath(filepath) {
    std::ifstream in(filepath);
    if (!in.is_open()) {
        throw Exceptions::FileCannotBeOpened("File " + filepath + " cannot be opened.");
    }
}

std::string ReaderUtil::FileReader::read() const {
    std::string result;
    std::ifstream in(m_filepath.c_str());
    if (in.is_open()) {
        in >> std::noskipws;
        std::copy(std::istream_iterator<char>(in), std::istream_iterator<char>(), std::back_inserter(result));
    } else {
        throw Exceptions::FileCannotBeOpened("File " + m_filepath + " cannot be opened.");
    }
    return result;
}

std::vector<std::string> ReaderUtil::FileReader::readlines() const {
    std::vector<std::string> result;
    std::ifstream in(m_filepath.c_str());
    if (in.is_open()) {
        std::string line;
        while (std::getline(in, line)) {
            result.push_back(std::move(line));
        }
    } else {
        throw Exceptions::FileCannotBeOpened("File " + m_filepath + " cannot be opened.");
    }
    return result;
}
