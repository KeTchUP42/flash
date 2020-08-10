//
// Created by roman on 10.08.2020.
//

#ifndef FLASH_INIPARSER_H
#define FLASH_INIPARSER_H

#include "../reader/FileReader.h"
#include "analyzer/Analyzer.h"
#include "../writer/Writer.h"
#include "../reader/Reader.h"

#include <memory>

namespace IniParseUtil {

    class IniParser {
    public:

        explicit IniParser(ReaderUtil::Reader *reader, Analyzer *analyzer)
                : _reader(reader), _analyzer(analyzer) {}

        explicit IniParser(const std::string &filepath, Analyzer *analyzer)
                : _reader(new ReaderUtil::FileReader(filepath)), _analyzer(analyzer) {}

        explicit IniParser(const std::string &filepath, const std::shared_ptr<Analyzer> &analyzer)
                : _reader(new ReaderUtil::FileReader(filepath)), _analyzer(analyzer) {}

        explicit IniParser(const std::shared_ptr<ReaderUtil::Reader> &reader, const std::shared_ptr<Analyzer> &analyzer)
                : _reader(reader), _analyzer(analyzer) {}

        IniParser &operator=(const IniParser &) = delete;

        /**
         * Method returns full ini config data in IniData type.
         * Configs without block will bee in "" field.
         *
         * @return Analyzer::IniData
         */
        virtual Analyzer::IniData fullparse() const noexcept = 0;

        /**
          * Method returns full ini config data in IniData type.
          * Configs without block will bee in "" field.
          * This method uses custom reader from param.
          * Reader WILL BE DELETED!
          *
          * @return Analyzer::IniData
          */
        virtual Analyzer::IniData fullparse(ReaderUtil::Reader *reader) const noexcept = 0;

        /**
          * Method returns full ini config data in IniData type.
          * Configs without block will bee in "" field.
          * This method uses custom reader from param.
          *
          * @return Analyzer::IniData
          */
        virtual Analyzer::IniData fullparse(const std::shared_ptr<ReaderUtil::Reader> &reader) const noexcept = 0;

        /**
         * Method creates new ini or append new data with standard logger writer and inidata.
         *
         * @param data
         */
        virtual void
        createIni(const Analyzer::IniData &data, const std::shared_ptr<WriterUtil::Writer> &writer) const noexcept = 0;

        /**
         * Method creates new ini or append new data with standard logger writer and inidata.
         * This method WILL NOT delete writer, so be careful!
         *
         * @param data
         */
        virtual void
        createIni(const Analyzer::IniData &data, WriterUtil::Writer *writer) const noexcept = 0;

    protected:
        std::shared_ptr<ReaderUtil::Reader> _reader;
        std::shared_ptr<Analyzer> _analyzer;
    };
}
#endif //FLASH_INIPARSER_H
