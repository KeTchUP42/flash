//
// Created by roman on 04.08.2020.
//

#include "Logger.h"
#include "../../main/general/exceptions/KernelRuntimeException.h"

LoggerUtil::Logger::Logger(LoggerUtil::Writer *writer, LoggerUtil::Formatter<std::string> *formatter) {
    if (writer == nullptr) {
        delete formatter;
        throw KernelExceptions::KernelRuntimeException("Writer cannot be nullptr.");
    }
    if (formatter == nullptr) {
        delete writer;
        throw KernelExceptions::KernelRuntimeException("Formatter cannot be nullptr.");
    }
    _writer = writer;
    _formatter = formatter;
}

LoggerUtil::Logger::~Logger() {
    delete _writer;
    delete _formatter;
}
