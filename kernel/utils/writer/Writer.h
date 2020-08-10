//
// Created by roman on 04.08.2020.
//

#ifndef FLASH_WRITER_H
#define FLASH_WRITER_H

#include <string>

namespace WriterUtil {

    class Writer {
    public:
        Writer() = default;

        Writer &operator=(const Writer &) = delete;

        /**
         * Writer main method wich writes a strign to file or files
         */
        virtual bool write(const std::string &) const noexcept = 0;

        /**
         * Writer main method wich writes a 'C' string to file or files
         */
        virtual bool write(const char *) const noexcept = 0;

        virtual ~Writer() noexcept = default;
    };

}
#endif //FLASH_WRITER_H