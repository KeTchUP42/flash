//
// Created by roman on 05.08.2020.
//

#ifndef FLASH_KERNELLOGGERFORMATTER_H
#define FLASH_KERNELLOGGERFORMATTER_H

#include "Formatter.h"

namespace LoggerUtil {

    class KernelLoggerFormatter : public Formatter<std::string> {
    public:
        KernelLoggerFormatter() : Formatter() {}

        std::string format(const std::string &data) const noexcept override;

    private:
        std::string dateTimeNow() const noexcept;
    };
}

#endif //FLASH_KERNELLOGGERFORMATTER_H
