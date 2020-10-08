//
// Created by roman on 10.08.2020.
//

#include "BasicIniProcessor.h"

IniUtil::Analyzer::IniData IniUtil::BasicIniProcessor::fullparse() const noexcept {
    return m_analyzer->fullparse(m_reader->readlines());
}

IniUtil::Analyzer::IniData
IniUtil::BasicIniProcessor::fullparse(const ReaderUtil::Reader &reader) const noexcept {
    return m_analyzer->fullparse(reader.readlines());
}

IniUtil::Analyzer::IniData
IniUtil::BasicIniProcessor::fullparse(const std::shared_ptr<ReaderUtil::Reader> &reader) const noexcept {
    return m_analyzer->fullparse(reader->readlines());
}

void IniUtil::BasicIniProcessor::createIni(const IniUtil::Analyzer::IniData &data, const std::shared_ptr<WriterUtil::Writer> &writer,
                                           const std::ios::openmode &mode) const noexcept {
    this->createIni(data, *writer.get(), mode);
}

void IniUtil::BasicIniProcessor::createIni(const IniUtil::Analyzer::IniData &data, const WriterUtil::Writer &writer,
                                           const std::ios::openmode &mode) const noexcept {
    std::string inidata;
    for (const auto &block: data) {
        if (block.first == NONAME_BLOCK) {
            for (Analyzer::IniBlock::const_reverse_iterator line = block.second.rbegin();
                 line != block.second.rend(); ++line) {
                inidata = line->first + " = " + line->second + "\n" + inidata;
            }
            continue;
        }

        inidata.append("\n[" + block.first + "]\n");
        for (const auto &line: block.second) {
            inidata.append(line.first + " = " + line.second + "\n");
        }
    }
    writer.write(std::move(inidata), mode);
}
