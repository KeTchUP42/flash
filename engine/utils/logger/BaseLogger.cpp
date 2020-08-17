//
// Created by roman on 04.08.2020.
//

#include "BaseLogger.h"

void LoggerUtil::BaseLogger::emergency(const std::string &message) const noexcept {
    _writer->write(_formatter->format(std::string(" EMERGENCY: ") + message));
}

void LoggerUtil::BaseLogger::alert(const std::string &message) const noexcept {
    _writer->write(_formatter->format(std::string(" ALERT: ") + message));
}

void LoggerUtil::BaseLogger::critical(const std::string &message) const noexcept {
    _writer->write(_formatter->format(std::string(" CRITICAL: ") + message));
}

void LoggerUtil::BaseLogger::error(const std::string &message) const noexcept {
    _writer->write(_formatter->format(std::string(" ERROR: ") + message));
}

void LoggerUtil::BaseLogger::warning(const std::string &message) const noexcept {
    _writer->write(_formatter->format(std::string(" WARNING: ") + message));
}

void LoggerUtil::BaseLogger::notice(const std::string &message) const noexcept {
    _writer->write(_formatter->format(std::string(" NOTICE: ") + message));
}

void LoggerUtil::BaseLogger::info(const std::string &message) const noexcept {
    _writer->write(_formatter->format(std::string(" INFO: ") + message));
}

void LoggerUtil::BaseLogger::debug(const std::string &message) const noexcept {
    _writer->write(_formatter->format(std::string(" DEBUG: ") + message));
}
