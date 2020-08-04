//
// Created by roman on 04.08.2020.
//

#include "Logger.h"
#include "../../main/general/exceptions/KernelRuntimeException.h"

LoggerUtil::Logger::Logger(LoggerUtil::Writer *writer) {
    if (writer == nullptr) {
        throw KernelExceptions::KernelRuntimeException("Writer cannot be nullptr.");
    }
    _writer = writer;
}

LoggerUtil::Logger::~Logger() {
    delete _writer;
}
