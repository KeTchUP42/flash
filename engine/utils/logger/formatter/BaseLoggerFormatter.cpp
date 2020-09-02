//
// Created by roman on 05.08.2020.
//

#include "BaseLoggerFormatter.h"

std::string dateTimeNow() noexcept;

std::string LoggerUtil::BaseLoggerFormatter::format(const std::string &data) const noexcept {
    return dateTimeNow() + data + '\n';
}

std::string dateTimeNow() noexcept {
    const unsigned buffchars = 20;
    char buffer[buffchars];
    time_t seconds = time(nullptr);
    tm *timeinfo = localtime(&seconds);
    strftime(buffer, buffchars, "%Y-%I-%d %H:%M", timeinfo);
    return std::string(buffer);
}

