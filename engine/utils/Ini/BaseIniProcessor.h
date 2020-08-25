//
// Created by roman on 10.08.2020.
//

#ifndef FLASH_BASEINIPROCESSOR_H
#define FLASH_BASEINIPROCESSOR_H

#include "IniProcessor.h"
#include "analyzer/IniAnalyzer.h"

namespace IniProcessorUtil {

    class BaseIniProcessor : public IniProcessor {
    public:
        explicit BaseIniProcessor(ReaderUtil::Reader *reader, Analyzer *analyzer = new IniAnalyzer())
                : IniProcessor(reader, analyzer) {}

        explicit BaseIniProcessor(const std::string &filepath, Analyzer *analyzer = new IniAnalyzer())
                : IniProcessor(filepath, analyzer) {}

        explicit BaseIniProcessor(const std::string &filepath, const std::shared_ptr<Analyzer> &analyzer)
                : IniProcessor(filepath, analyzer) {}

        explicit BaseIniProcessor(const std::shared_ptr<ReaderUtil::Reader> &reader,
                                  const std::shared_ptr<Analyzer> &analyzer = std::shared_ptr<Analyzer>(new IniAnalyzer()))
                : IniProcessor(reader, analyzer) {}


        Analyzer::IniData fullparse() const noexcept override;

        Analyzer::IniData fullparse(ReaderUtil::Reader *reader) const noexcept override;

        Analyzer::IniData fullparse(const std::shared_ptr<ReaderUtil::Reader> &reader) const noexcept override;

        void createIni(const Analyzer::IniData &data, const std::shared_ptr<WriterUtil::Writer> &writer,
                       const std::ios::openmode &mode = std::ios_base::out | std::ios_base::trunc) const noexcept override;

        void createIni(const Analyzer::IniData &data, WriterUtil::Writer *writer,
                       const std::ios::openmode &mode = std::ios_base::out | std::ios_base::trunc) const noexcept override;
    };
}

#endif //FLASH_BASEINIPROCESSOR_H
