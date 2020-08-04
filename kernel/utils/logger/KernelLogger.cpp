//
// Created by roman on 04.08.2020.
//

#include "KernelLogger.h"

void LoggerUtil::KernelLogger::emergency(const std::string &message) const noexcept {
    _writer->write(dateTimeNow() + std::string(" EMERGENCY: ") + message + '\n');
}

void LoggerUtil::KernelLogger::alert(const std::string &message) const noexcept {
    _writer->write(dateTimeNow() + std::string(" ALERT: ") + message + '\n');
}

void LoggerUtil::KernelLogger::critical(const std::string &message) const noexcept {
    _writer->write(dateTimeNow() + std::string(" CRITICAL: ") + message + '\n');
}

void LoggerUtil::KernelLogger::error(const std::string &message) const noexcept {
    _writer->write(dateTimeNow() + std::string(" ERROR: ") + message + '\n');
}

void LoggerUtil::KernelLogger::warning(const std::string &message) const noexcept {
    _writer->write(dateTimeNow() + std::string(" WARNING: ") + message + '\n');
}

void LoggerUtil::KernelLogger::notice(const std::string &message) const noexcept {
    _writer->write(dateTimeNow() + std::string(" NOTICE: ") + message + '\n');
}

void LoggerUtil::KernelLogger::info(const std::string &message) const noexcept {
    _writer->write(dateTimeNow() + std::string(" INFO: ") + message + '\n');
}

void LoggerUtil::KernelLogger::debug(const std::string &message) const noexcept {
    _writer->write(dateTimeNow() + std::string(" DEBUG: ") + message + '\n');
}

std::string LoggerUtil::KernelLogger::dateTimeNow() const noexcept {
    const unsigned int buffchars = 20;
    char buffer[buffchars];
    time_t seconds = time(nullptr);
    tm *timeinfo = localtime(&seconds);
    strftime(buffer, buffchars, "%Y-%I-%d %H:%M", timeinfo);

    std::string datetime = std::string(buffer);
    return datetime;
}
