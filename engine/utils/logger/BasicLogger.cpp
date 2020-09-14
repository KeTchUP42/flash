//
// Created by roman on 04.08.2020.
//

#include "BasicLogger.h"

void LoggerUtil::BasicLogger::emergency(const std::string &message) const noexcept {
    _writer->write(_formatter->format(" EMERGENCY: " + message));
}

void LoggerUtil::BasicLogger::alert(const std::string &message) const noexcept {
    _writer->write(_formatter->format(" ALERT: " + message));
}

void LoggerUtil::BasicLogger::critical(const std::string &message) const noexcept {
    _writer->write(_formatter->format(" CRITICAL: " + message));
}

void LoggerUtil::BasicLogger::error(const std::string &message) const noexcept {
    _writer->write(_formatter->format(" ERROR: " + message));
}

void LoggerUtil::BasicLogger::warning(const std::string &message) const noexcept {
    _writer->write(_formatter->format(" WARNING: " + message));
}

void LoggerUtil::BasicLogger::notice(const std::string &message) const noexcept {
    _writer->write(_formatter->format(" NOTICE: " + message));
}

void LoggerUtil::BasicLogger::info(const std::string &message) const noexcept {
    _writer->write(_formatter->format(" INFO: " + message));
}

void LoggerUtil::BasicLogger::debug(const std::string &message) const noexcept {
    _writer->write(_formatter->format(" DEBUG: " + message));
}
