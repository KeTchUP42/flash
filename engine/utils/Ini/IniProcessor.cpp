//
// Created by roman on 20.10.2020.
//

#include "IniProcessor.h"

const std::string IniUtil::IniProcessor::NONAME_BLOCK = "";

IniUtil::Analyzer::IniData IniUtil::IniProcessor::fullparse() const {
    return m_analyzer->fullparse(m_reader->readlines());
}

bool IniUtil::IniProcessor::createIni(const IniUtil::Analyzer::IniData &data, const std::ios_base::openmode &mode) const {
    return m_writer->write(m_creator->create(data), mode);
}