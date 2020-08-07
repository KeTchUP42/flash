//
// Created by roman on 04.08.2020.
//

#include "Logger.h"
#include "../../main/general/exceptions/InvalidArgument.h"

LoggerUtil::Logger::Logger(LoggerUtil::Writer *writer, LoggerUtil::Formatter<std::string> *formatter) {
    if (writer == nullptr) {
        delete formatter;
        throw KernelExceptions::InvalidArgument("Writer cannot be nullptr.");
    }
    if (formatter == nullptr) {
        delete writer;
        throw KernelExceptions::InvalidArgument("Formatter cannot be nullptr.");
    }
    _writer = writer;
    _formatter = formatter;
}

LoggerUtil::Logger::~Logger() noexcept{
    delete _writer;
    delete _formatter;
}
