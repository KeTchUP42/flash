cmake_minimum_required(VERSION 3.16)
project(Flash)

set(CMAKE_CXX_STANDARD 11)

set(SFML_DIR ./lib/SFML-2.5.1/lib/cmake/SFML)

find_package(SFML 2.5.1 COMPONENTS window graphics audio)

add_executable(Flash init/main.cpp kernel/init/Kernel.cpp kernel/init/Kernel.h kernel/utils/logger/Logger.h kernel/utils/logger/writer/Writer.h kernel/main/general/exceptions/RuntimeException.h kernel/main/general/exceptions/Exception.cpp kernel/main/general/exceptions/Exception.h kernel/utils/logger/writer/FileWriter.cpp kernel/utils/logger/writer/FileWriter.h kernel/utils/logger/KernelLogger.cpp kernel/utils/logger/KernelLogger.h kernel/utils/logger/Logger.cpp kernel/utils/logger/formatter/Formatter.h kernel/utils/logger/formatter/KernelLoggerFormatter.cpp kernel/utils/logger/formatter/KernelLoggerFormatter.h kernel/main/general/exceptions/LogicError.h kernel/main/general/exceptions/InvalidArgument.h kernel/utils/logger/writer/MultiWriter.cpp kernel/utils/logger/writer/MultiWriter.h kernel/main/general/exceptions/custom/FileCanNotBeOpened.h kernel/main/general/exceptions/ExceptionCodes.h kernel/utils/Ini/reader/Reader.h kernel/utils/Ini/reader/FileReader.cpp kernel/utils/Ini/reader/FileReader.h)

target_link_libraries(Flash sfml-window sfml-graphics sfml-audio)
