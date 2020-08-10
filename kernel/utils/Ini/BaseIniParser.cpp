//
// Created by roman on 10.08.2020.
//

#include "BaseIniParser.h"

IniParseUtil::Analyzer::IniData IniParseUtil::BaseIniParser::fullparse() const noexcept {
    return _analyzer->fullparse(_reader->readlines());
}

IniParseUtil::Analyzer::IniData IniParseUtil::BaseIniParser::fullparse(ReaderUtil::Reader *reader) const noexcept {
    Analyzer::IniData result = _analyzer->fullparse(reader->readlines());
    delete reader;
    return std::move(result);
}

IniParseUtil::Analyzer::IniData
IniParseUtil::BaseIniParser::fullparse(const std::shared_ptr<ReaderUtil::Reader> &reader) const noexcept {
    return _analyzer->fullparse(reader->readlines());
}

void IniParseUtil::BaseIniParser::createIni(const IniParseUtil::Analyzer::IniData &data,
                                            const std::shared_ptr<WriterUtil::Writer> &writer) const noexcept {
    // todo: write code func NO DELETE
}

void
IniParseUtil::BaseIniParser::createIni(const IniParseUtil::Analyzer::IniData &data, WriterUtil::Writer *writer) const noexcept {
    // todo: write code func
}
