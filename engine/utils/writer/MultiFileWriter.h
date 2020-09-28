//
// Created by roman on 07.08.2020.
//

#ifndef FLASH_MULTIFILEWRITER_H
#define FLASH_MULTIFILEWRITER_H

#include "Writer.h"

#include <list>
#include <vector>

namespace WriterUtil {

    class MultiFileWriter : public Writer {
    public:
        MultiFileWriter() = default;

        MultiFileWriter(const std::list<std::string> &filepaths);

        MultiFileWriter(const std::vector<std::string> &filepaths);

        void add(const std::string &filepath);

        void add(const std::list<std::string> &paths);

        void add(const std::vector<std::string> &paths);

        void remove(const std::string &filepath) noexcept;

        bool write(const std::string &message, const std::ios::openmode &mode) const noexcept override;

        bool write(const char *message, const std::ios::openmode &mode) const noexcept override;

    protected:
        std::list<std::string> m_filepaths;
    };
}

#endif //FLASH_MULTIFILEWRITER_H
