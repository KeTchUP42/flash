cmake_minimum_required(VERSION 3.16)
project(Flash)

set(CMAKE_CXX_STANDARD 11)

set(SFML_DIR ./lib/SFML-2.5.1/lib/cmake/SFML)

find_package(SFML 2.5.1 COMPONENTS window graphics audio)

set(MAIN init/main.cpp)
add_executable(Flash ${MAIN} kernel/init/Kernel.cpp kernel/init/Kernel.h kernel/utils/logger/Logger.h kernel/utils/writer/Writer.h kernel/main/general/exceptions/RuntimeException.h kernel/main/general/exceptions/Exception.cpp kernel/main/general/exceptions/Exception.h kernel/utils/writer/FileWriter.cpp kernel/utils/writer/FileWriter.h kernel/utils/logger/KernelLogger.cpp kernel/utils/logger/KernelLogger.h kernel/utils/logger/formatter/Formatter.h kernel/utils/logger/formatter/KernelLoggerFormatter.cpp kernel/utils/logger/formatter/KernelLoggerFormatter.h kernel/main/general/exceptions/LogicError.h kernel/main/general/exceptions/InvalidArgument.h kernel/utils/writer/MultiWriter.cpp kernel/utils/writer/MultiWriter.h kernel/main/general/exceptions/custom/FileCanNotBeOpened.h kernel/main/general/exceptions/ExceptionCodes.h kernel/utils/reader/Reader.h kernel/utils/reader/FileReader.cpp kernel/utils/reader/FileReader.h kernel/utils/Ini/IniParser.h kernel/utils/Ini/analyzer/Analyzer.h kernel/utils/Ini/BaseIniParser.cpp kernel/utils/Ini/BaseIniParser.h kernel/utils/Ini/analyzer/IniAnalyzer.cpp kernel/utils/Ini/analyzer/IniAnalyzer.h)

target_link_libraries(Flash sfml-window sfml-graphics sfml-audio)
