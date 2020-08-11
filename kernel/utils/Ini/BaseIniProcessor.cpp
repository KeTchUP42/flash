//
// Created by roman on 10.08.2020.
//

#include "BaseIniProcessor.h"

IniProcessorUtil::Analyzer::IniData IniProcessorUtil::BaseIniProcessor::fullparse() const noexcept {
    return _analyzer->fullparse(_reader->readlines());
}

IniProcessorUtil::Analyzer::IniData IniProcessorUtil::BaseIniProcessor::fullparse(ReaderUtil::Reader *reader) const noexcept {
    Analyzer::IniData result = _analyzer->fullparse(reader->readlines());
    delete reader;
    return std::move(result);
}

IniProcessorUtil::Analyzer::IniData
IniProcessorUtil::BaseIniProcessor::fullparse(const std::shared_ptr<ReaderUtil::Reader> &reader) const noexcept {
    return _analyzer->fullparse(reader->readlines());
}

void IniProcessorUtil::BaseIniProcessor::createIni(const IniProcessorUtil::Analyzer::IniData &data,
                                                   const std::shared_ptr<WriterUtil::Writer> &writer,
                                                   const std::ios::openmode &mode) const noexcept {
    this->createIni(data, writer.get(), mode);
}

void IniProcessorUtil::BaseIniProcessor::createIni(const IniProcessorUtil::Analyzer::IniData &data,
                                                   WriterUtil::Writer *writer, const std::ios::openmode &mode) const noexcept {
    std::string inidata;
    for (Analyzer::IniData::const_iterator section = data.cbegin(); section != data.cend(); ++section) {

        if (section->first == CONFIG_LINES_WITHOUT_BLOCK) {
            for (Analyzer::IniLine::const_reverse_iterator line = section->second.rbegin();
                 line != section->second.rend(); ++line) {
                inidata = line->first + " = " + line->second + "\n" + inidata;
            }
            continue;
        }

        inidata.append("\n[" + section->first + "]\n");
        for (Analyzer::IniLine::const_iterator line = section->second.cbegin(); line != section->second.cend(); ++line) {
            inidata.append(line->first + " = " + line->second + "\n");
        }
    }
    writer->write(std::move(inidata), mode);
}
