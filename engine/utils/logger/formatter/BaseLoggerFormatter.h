//
// Created by roman on 05.08.2020.
//

#ifndef FLASH_BASELOGGERFORMATTER_H
#define FLASH_BASELOGGERFORMATTER_H

#include "Formatter.h"

namespace LoggerUtil {

    class BaseLoggerFormatter : public Formatter<std::string> {
    public:
        std::string format(const std::string &data) const noexcept override;
    };
}

#endif //FLASH_BASELOGGERFORMATTER_H
