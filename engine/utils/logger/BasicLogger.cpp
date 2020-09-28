//
// Created by roman on 04.08.2020.
//

#include "BasicLogger.h"

void LoggerUtil::BasicLogger::emergency(const std::string &message) const noexcept {
    m_writer->write(m_formatter->format(" EMERGENCY: " + message), std::ios::app);
}

void LoggerUtil::BasicLogger::alert(const std::string &message) const noexcept {
    m_writer->write(m_formatter->format(" ALERT: " + message), std::ios::app);
}

void LoggerUtil::BasicLogger::critical(const std::string &message) const noexcept {
    m_writer->write(m_formatter->format(" CRITICAL: " + message), std::ios::app);
}

void LoggerUtil::BasicLogger::error(const std::string &message) const noexcept {
    m_writer->write(m_formatter->format(" ERROR: " + message), std::ios::app);
}

void LoggerUtil::BasicLogger::warning(const std::string &message) const noexcept {
    m_writer->write(m_formatter->format(" WARNING: " + message), std::ios::app);
}

void LoggerUtil::BasicLogger::notice(const std::string &message) const noexcept {
    m_writer->write(m_formatter->format(" NOTICE: " + message), std::ios::app);
}

void LoggerUtil::BasicLogger::info(const std::string &message) const noexcept {
    m_writer->write(m_formatter->format(" INFO: " + message), std::ios::app);
}

void LoggerUtil::BasicLogger::debug(const std::string &message) const noexcept {
    m_writer->write(m_formatter->format(" DEBUG: " + message), std::ios::app);
}
