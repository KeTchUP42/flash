//
// Created by roman on 10.08.2020.
//

#include "BaseIniProcessor.h"

IniParseUtil::Analyzer::IniData IniParseUtil::BaseIniProcessor::fullparse() const noexcept {
    return _analyzer->fullparse(_reader->readlines());
}

IniParseUtil::Analyzer::IniData IniParseUtil::BaseIniProcessor::fullparse(ReaderUtil::Reader *reader) const noexcept {
    Analyzer::IniData result = _analyzer->fullparse(reader->readlines());
    delete reader;
    return std::move(result);
}

IniParseUtil::Analyzer::IniData
IniParseUtil::BaseIniProcessor::fullparse(const std::shared_ptr<ReaderUtil::Reader> &reader) const noexcept {
    return _analyzer->fullparse(reader->readlines());
}

void IniParseUtil::BaseIniProcessor::createIni(const IniParseUtil::Analyzer::IniData &data,
                                               const std::shared_ptr<WriterUtil::Writer> &writer) const noexcept {
    // todo: write code func
}

void
IniParseUtil::BaseIniProcessor::createIni(const IniParseUtil::Analyzer::IniData &data,
                                          WriterUtil::Writer *writer) const noexcept {
    std::string inidata;
    for (Analyzer::IniData::const_iterator i = data.cbegin(); i != data.cend(); ++i) {
        // todo:!!! NO_BLOCK_CONFIG_LINES !!
    }
}
