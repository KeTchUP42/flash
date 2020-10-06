//
// Created by roman on 05.08.2020.
//

#ifndef FLASH_LOGGERFORMATTER_H
#define FLASH_LOGGERFORMATTER_H

#include "Formatter.h"

namespace LoggerUtil {

    class LoggerFormatter : public Formatter<std::string> {
    public:
        std::string format(const std::string &data) const noexcept override;
    };
}

#endif //FLASH_LOGGERFORMATTER_H
