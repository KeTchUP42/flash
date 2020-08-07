//
// Created by roman on 07.08.2020.
//

#ifndef FLASH_MULTIWRITER_H
#define FLASH_MULTIWRITER_H

#include <list>
#include <vector>
#include "Writer.h"

namespace LoggerUtil {
    class MultiWriter : public Writer {
    public:
        MultiWriter() = default;

        explicit MultiWriter(const std::list<std::string> &paths);

        explicit MultiWriter(const std::vector<std::string> &paths);

        void add(const std::string &filepath);

        void add(const std::list<std::string> &paths);

        void add(const std::vector<std::string> &paths);

        void remove(const std::string &filepath) noexcept;

        bool write(const std::string &message) const noexcept override;

        bool write(const char *message) const noexcept override;

    protected:
        bool checkPath(const std::string &filepath) const noexcept;

        std::list<std::string> _paths;
    };
}

#endif //FLASH_MULTIWRITER_H
