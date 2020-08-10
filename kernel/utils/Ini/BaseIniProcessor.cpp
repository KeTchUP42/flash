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
                                                   const std::shared_ptr<WriterUtil::Writer> &writer) const noexcept {
    // todo: write code func
}

void
IniProcessorUtil::BaseIniProcessor::createIni(const IniProcessorUtil::Analyzer::IniData &data,
                                              WriterUtil::Writer *writer) const noexcept {
    std::string inidata;
    for (Analyzer::IniData::const_iterator i = data.cbegin(); i != data.cend(); ++i) {
        // todo:!!! NO_BLOCK_CONFIG_LINES !!
    }
}
