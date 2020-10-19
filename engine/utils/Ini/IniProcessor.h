//
// Created by roman on 10.08.2020.
//

#ifndef FLASH_INIPROCESSOR_H
#define FLASH_INIPROCESSOR_H

#include "../reader/FileReader.h"
#include "../writer/Writer.h"
#include "../reader/Reader.h"
#include "analyzer/Analyzer.h"
#include "analyzer/IniAnalyzer.h"

#include <memory>

namespace IniUtil {

    /**
     * @brief The class contains an implementation of the processor of ini files. It can analyze and create them.
     * @namespace IniUtil
     *
     * This class defines interface and fields of IniProcessor classes.
    */
    class IniProcessor {
    public:
        explicit IniProcessor(ReaderUtil::Reader *reader, Analyzer *analyzer = new IniAnalyzer())
                : m_reader(reader), m_analyzer(analyzer) {}

        explicit IniProcessor(const std::string &filepath, Analyzer *analyzer = new IniAnalyzer())
                : m_reader(new ReaderUtil::FileReader(filepath)), m_analyzer(analyzer) {}

        explicit IniProcessor(const std::string &filepath, const std::shared_ptr<Analyzer> &analyzer)
                : m_reader(new ReaderUtil::FileReader(filepath)), m_analyzer(analyzer) {}

        explicit IniProcessor(const std::shared_ptr<ReaderUtil::Reader> &reader,
                              const std::shared_ptr<Analyzer> &analyzer = std::shared_ptr<Analyzer>(new IniAnalyzer()))
                : m_reader(reader), m_analyzer(analyzer) {}

        /**
         * Default configs without block IniData section name.
         */
        static constexpr const char *NONAME_BLOCK = "";

        /**
         * Method returns full ini config data in IniData type.
         * Configs without block will be in NONAME_BLOCK section.
         *
         * @return Analyzer::IniData
         */
        Analyzer::IniData fullparse() const noexcept;

        /**
          * Method returns full ini config data in IniData type.
          * Configs without block will be in NONAME_BLOCK section.
          * This method uses custom reader.
          *
          * @param reader Reader
          * @return Analyzer::IniData
          */
        Analyzer::IniData fullparse(const ReaderUtil::Reader &reader) const noexcept;

        /**
          * Method returns full ini config data in IniData type.
          * Configs without block will be in NONAME_BLOCK section.
          * This method uses custom reader.
          *
          * @param reader Reader
          * @return Analyzer::IniData
          */
        Analyzer::IniData fullparse(const std::shared_ptr<ReaderUtil::Reader> &reader) const noexcept;

        /**
         * Method creates new ini file or append new data with standard writer.
         *
         * @param data Analyzer::IniData
         * @param writer Writer
         */
        virtual void createIni(const Analyzer::IniData &data, const std::shared_ptr<WriterUtil::Writer> &writer,
                               const std::ios::openmode &mode = std::ios_base::out | std::ios_base::trunc) const noexcept;

        /**
         * Method creates new ini file or append new data with standard writer.
         *
         * @param data Analyzer::IniData
         * @param writer Writer
         **/
        virtual void createIni(const Analyzer::IniData &data, const WriterUtil::Writer &writer,
                               const std::ios::openmode &mode = std::ios_base::out | std::ios_base::trunc) const noexcept;


        virtual ~IniProcessor() = default;

    protected:
        std::shared_ptr<ReaderUtil::Reader> m_reader;
        std::shared_ptr<Analyzer> m_analyzer;
    };
}
#endif //FLASH_INIPROCESSOR_H
