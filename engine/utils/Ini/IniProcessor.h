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
#include "creator/Creator.h"
#include "creator/IniCreator.h"
#include "../writer/FileWriter.h"

#include <memory>

namespace IniUtil {

    /**
     * @brief The class contains an implementation of the processor of ini-files. It can analyze and create them.
     * @namespace IniUtil
     *
     * This class defines interface and fields of IniProcessor classes.
    */
    class IniProcessor {
    public:
        explicit IniProcessor(const std::string &filepath, Analyzer *analyzer = new IniAnalyzer(), Creator *creator = new IniCreator())
                : m_reader(new ReaderUtil::FileReader(filepath)), m_writer(new WriterUtil::FileWriter(filepath)), m_analyzer(analyzer), m_creator(creator) {}

        explicit IniProcessor(ReaderUtil::Reader *reader, WriterUtil::Writer *writer, Analyzer *analyzer = new IniAnalyzer(), Creator *creator = new IniCreator())
                : m_reader(reader), m_writer(writer), m_analyzer(analyzer), m_creator(creator) {}

        /**
         * Default configs without block IniData section name.
         */
        static const std::string NONAME_BLOCK;

        /**
         * Method returns full ini config data in IniData type.
         * Configs without block will be in NONAME_BLOCK section.
         *
         * @return Analyzer::IniData
         */
        Analyzer::IniData fullparse() const;

        /**
         * @brief Method creates new ini file or append new data with standard writer.
         * @param data Needed Ini-file data struct.
         * @return Was success?
         */
        bool createIni(const Analyzer::IniData &data, const std::ios::openmode &mode = std::ios_base::out | std::ios_base::trunc) const;

        virtual ~IniProcessor() = default;

    private:
        std::shared_ptr<ReaderUtil::Reader> m_reader;
        std::shared_ptr<WriterUtil::Writer> m_writer;
        std::shared_ptr<Analyzer> m_analyzer;
        std::shared_ptr<Creator> m_creator;
    };
}
#endif //FLASH_INIPROCESSOR_H
