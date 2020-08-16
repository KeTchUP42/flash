//
// Created by roman on 04.08.2020.
//

#include "KernelLogger.h"

void LoggerUtil::KernelLogger::emergency(const std::string &message) const noexcept {
    _writer->write(_formatter->format(std::string(" EMERGENCY: ") + message));
}

void LoggerUtil::KernelLogger::alert(const std::string &message) const noexcept {
    _writer->write(_formatter->format(std::string(" ALERT: ") + message));
}

void LoggerUtil::KernelLogger::critical(const std::string &message) const noexcept {
    _writer->write(_formatter->format(std::string(" CRITICAL: ") + message));
}

void LoggerUtil::KernelLogger::error(const std::string &message) const noexcept {
    _writer->write(_formatter->format(std::string(" ERROR: ") + message));
}

void LoggerUtil::KernelLogger::warning(const std::string &message) const noexcept {
    _writer->write(_formatter->format(std::string(" WARNING: ") + message));
}

void LoggerUtil::KernelLogger::notice(const std::string &message) const noexcept {
    _writer->write(_formatter->format(std::string(" NOTICE: ") + message));
}

void LoggerUtil::KernelLogger::info(const std::string &message) const noexcept {
    _writer->write(_formatter->format(std::string(" INFO: ") + message));
}

void LoggerUtil::KernelLogger::debug(const std::string &message) const noexcept {
    _writer->write(_formatter->format(std::string(" DEBUG: ") + message));
}
