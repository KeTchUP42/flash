//
// Created by roman on 10.08.2020.
//

#ifndef FLASH_INIPARSER_H
#define FLASH_INIPARSER_H

#include "reader/FileReader.h"
#include "analyzer/Analyzer.h"
#include "../logger/writer/Writer.h"

#include <memory>

namespace IniParseUtil {

    class IniParser {
    public:
        IniParser &operator=(const IniParser &) = delete;

        explicit IniParser(Reader *reader, Analyzer *analyzer)
                : _reader(reader), _analyzer(analyzer) {}

        explicit IniParser(const std::string &filepath, Analyzer *analyzer)
                : _reader(new FileReader(filepath)), _analyzer(analyzer) {}

        explicit IniParser(const std::string &filepath, const std::shared_ptr<Analyzer> &analyzer)
                : _reader(new FileReader(filepath)), _analyzer(analyzer) {}

        explicit IniParser(const std::shared_ptr<Reader> &reader, const std::shared_ptr<Analyzer> &analyzer)
                : _reader(reader), _analyzer(analyzer) {}

        /**
         * Method returns full ini config data in IniData type.
         * Configs without own block name will bee in "" field
         *
         * @return Analyzer::IniData
         */
        virtual Analyzer::IniData fullparse() const noexcept = 0;

        /**
         * Method generates new ini or append new data to file with standard logger writer and inidata.
         *
         * @param data
         */
        virtual void
        generateIni(const Analyzer::IniData &data, const std::shared_ptr<LoggerUtil::Writer> &writer) const noexcept = 0;

        /**
         * Method generates new ini or append new data to file with standard logger writer and inidata.
         * This method WILL NOT delete writer obj, so be careful!
         *
         * @param data
         */
        virtual void
        generateIni(const Analyzer::IniData &data, LoggerUtil::Writer *writer) const noexcept = 0;

    protected:
        std::shared_ptr<Reader> _reader;
        std::shared_ptr<Analyzer> _analyzer;
    };
}
#endif //FLASH_INIPARSER_H
