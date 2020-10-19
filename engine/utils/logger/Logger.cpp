//
// Created by roman on 20.10.2020.
//

#include "Logger.h"

void LoggerUtil::Logger::emergency(const std::string &message) const noexcept {
    m_writer->write(m_formatter->format(" EMERGENCY: " + message), std::ios::app);
}

void LoggerUtil::Logger::alert(const std::string &message) const noexcept {
    m_writer->write(m_formatter->format(" ALERT: " + message), std::ios::app);
}

void LoggerUtil::Logger::critical(const std::string &message) const noexcept {
    m_writer->write(m_formatter->format(" CRITICAL: " + message), std::ios::app);
}

void LoggerUtil::Logger::error(const std::string &message) const noexcept {
    m_writer->write(m_formatter->format(" ERROR: " + message), std::ios::app);
}

void LoggerUtil::Logger::warning(const std::string &message) const noexcept {
    m_writer->write(m_formatter->format(" WARNING: " + message), std::ios::app);
}

void LoggerUtil::Logger::notice(const std::string &message) const noexcept {
    m_writer->write(m_formatter->format(" NOTICE: " + message), std::ios::app);
}

void LoggerUtil::Logger::info(const std::string &message) const noexcept {
    m_writer->write(m_formatter->format(" INFO: " + message), std::ios::app);
}

void LoggerUtil::Logger::debug(const std::string &message) const noexcept {
    m_writer->write(m_formatter->format(" DEBUG: " + message), std::ios::app);
}