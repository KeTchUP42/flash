//
// Created by roman on 10.08.2020.
//

#ifndef FLASH_BASEINIPARSER_H
#define FLASH_BASEINIPARSER_H

#include "IniParser.h"
#include "analyzer/IniAnalyzer.h"

namespace IniParseUtil {
    class BaseIniParser : public IniParser {
    public:
        Analyzer::IniData fullparse(ReaderUtil::Reader *reader) const noexcept override;

        Analyzer::IniData fullparse(const std::shared_ptr<ReaderUtil::Reader> &reader) const noexcept override;

        explicit BaseIniParser(ReaderUtil::Reader *reader, Analyzer *analyzer = new IniAnalyzer())
                : IniParser(reader, analyzer) {}

        explicit BaseIniParser(const std::string &filepath, Analyzer *analyzer = new IniAnalyzer())
                : IniParser(filepath, analyzer) {}

        explicit BaseIniParser(const std::string &filepath,
                               const std::shared_ptr<Analyzer> &analyzer = std::shared_ptr<Analyzer>(new IniAnalyzer()))
                : IniParser(filepath, analyzer) {}

        explicit BaseIniParser(const std::shared_ptr<ReaderUtil::Reader> &reader,
                               const std::shared_ptr<Analyzer> &analyzer = std::shared_ptr<Analyzer>(new IniAnalyzer()))
                : IniParser(reader, analyzer) {}


        Analyzer::IniData fullparse() const noexcept override;

        void createIni(const Analyzer::IniData &data, const std::shared_ptr<WriterUtil::Writer> &writer) const noexcept override;

        void createIni(const Analyzer::IniData &data, WriterUtil::Writer *writer) const noexcept override;
    };
}

#endif //FLASH_BASEINIPARSER_H
