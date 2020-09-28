//
// Created by roman on 10.08.2020.
//

#include "BasicIniProcessor.h"

IniProcessorUtil::Analyzer::IniData IniProcessorUtil::BasicIniProcessor::fullparse() const noexcept {
    return m_analyzer->fullparse(m_reader->readlines());
}

IniProcessorUtil::Analyzer::IniData
IniProcessorUtil::BasicIniProcessor::fullparse(const ReaderUtil::Reader &reader) const noexcept {
    return m_analyzer->fullparse(reader.readlines());
}

IniProcessorUtil::Analyzer::IniData
IniProcessorUtil::BasicIniProcessor::fullparse(const std::shared_ptr<ReaderUtil::Reader> &reader) const noexcept {
    return m_analyzer->fullparse(reader->readlines());
}

void IniProcessorUtil::BasicIniProcessor::createIni(const IniProcessorUtil::Analyzer::IniData &data, const std::shared_ptr<WriterUtil::Writer> &writer,
                                                    const std::ios::openmode &mode) const noexcept {
    this->createIni(data, *writer.get(), mode);
}

void IniProcessorUtil::BasicIniProcessor::createIni(const IniProcessorUtil::Analyzer::IniData &data, const WriterUtil::Writer &writer,
                                                    const std::ios::openmode &mode) const noexcept {
    std::string inidata;
    for (Analyzer::IniData::const_iterator block = data.cbegin(); block != data.cend(); ++block) {

        if (block->first == NONAME_BLOCK) {
            for (Analyzer::IniBlock::const_reverse_iterator line = block->second.rbegin();
                 line != block->second.rend(); ++line) {
                inidata = line->first + " = " + line->second + "\n" + inidata;
            }
            continue;
        }

        inidata.append("\n[" + block->first + "]\n");
        for (Analyzer::IniBlock::const_iterator line = block->second.cbegin(); line != block->second.cend(); ++line) {
            inidata.append(line->first + " = " + line->second + "\n");
        }
    }
    writer.write(std::move(inidata), mode);
}
