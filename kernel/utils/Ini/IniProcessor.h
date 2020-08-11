//
// Created by roman on 10.08.2020.
//

#ifndef FLASH_INIPROCESSOR_H
#define FLASH_INIPROCESSOR_H

#include "../reader/FileReader.h"
#include "../writer/Writer.h"
#include "../reader/Reader.h"
#include "analyzer/Analyzer.h"

#include <memory>

namespace IniProcessorUtil {

    /**
     *  @brief  The base class of the IniProcessor class hierarchy.
     *  @namespace IniProcessorUtil
     *
     *  This class defines base interface and fields of IniProcessor classes.
    */
    class IniProcessor {
    public:
        explicit IniProcessor(ReaderUtil::Reader *reader, Analyzer *analyzer)
                : _reader(reader), _analyzer(analyzer) {}

        explicit IniProcessor(const std::string &filepath, Analyzer *analyzer)
                : _reader(new ReaderUtil::FileReader(filepath)), _analyzer(analyzer) {}

        explicit IniProcessor(const std::string &filepath, const std::shared_ptr<Analyzer> &analyzer)
                : _reader(new ReaderUtil::FileReader(filepath)), _analyzer(analyzer) {}

        explicit IniProcessor(const std::shared_ptr<ReaderUtil::Reader> &reader, const std::shared_ptr<Analyzer> &analyzer)
                : _reader(reader), _analyzer(analyzer) {}

        IniProcessor &operator=(const IniProcessor &) = delete;

        /**
         * Default configs without block section name.
         */
        static constexpr const char *CONFIG_LINES_WITHOUT_BLOCK = "";

        /**
         * Method returns full ini config data in IniData type.
         * Configs without block will be in CONFIG_LINES_WITHOUT_BLOCK section.
         *
         * @return Analyzer::IniData
         */
        virtual Analyzer::IniData fullparse() const noexcept = 0;

        /**
          * Method returns full ini config data in IniData type.
          * Configs without block will be in CONFIG_LINES_WITHOUT_BLOCK section.
          * This method uses custom reader.
          * Reader WILL BE DELETED!
          *
          * @param reader Reader
          * @return Analyzer::IniData
          */
        virtual Analyzer::IniData fullparse(ReaderUtil::Reader *reader) const noexcept = 0;

        /**
          * Method returns full ini config data in IniData type.
          * Configs without block will be in CONFIG_LINES_WITHOUT_BLOCK section.
          * This method uses custom reader.
          *
          * @param reader Reader
          * @return Analyzer::IniData
          */
        virtual Analyzer::IniData fullparse(const std::shared_ptr<ReaderUtil::Reader> &reader) const noexcept = 0;

        /**
         * Method creates new ini or append new data with standard writer and IniData.
         *
         * @param data Analyzer::IniData
         * @param writer Writer
         */
        virtual void
        createIni(const Analyzer::IniData &data, const std::shared_ptr<WriterUtil::Writer> &writer,
                  const std::ios::openmode &mode = std::ios_base::out | std::ios_base::trunc) const noexcept = 0;

        /**
         * Method creates new ini or append new data with standard writer and IniData.
         * This method WILL NOT delete writer, so be careful!
         *
         * @param data Analyzer::IniData
         * @param writer Writer
         **/
        virtual void
        createIni(const Analyzer::IniData &data, WriterUtil::Writer *writer,
                  const std::ios::openmode &mode = std::ios_base::out | std::ios_base::trunc) const noexcept = 0;

    protected:
        std::shared_ptr<ReaderUtil::Reader> _reader;
        std::shared_ptr<Analyzer> _analyzer;
    };
}
#endif //FLASH_INIPROCESSOR_H
