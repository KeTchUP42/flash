cmake_minimum_required(VERSION 3.16)
project(Flash)

set(CMAKE_CXX_STANDARD 11)

set(SFML_DIR ./lib/SFML-2.5.1/lib/cmake/SFML)

find_package(SFML 2.5.1 COMPONENTS window graphics audio)

set(MAIN init/main.cpp)
set(ENGINE engine/init/Engine.cpp engine/init/Engine.h)

set(PLAYER engine/main/audio/player/AudioPlayer.h engine/main/audio/player/MusicPlayer.cpp engine/main/audio/player/MusicPlayer.h engine/main/audio/player/SoundPlayer.cpp engine/main/audio/player/SoundPlayer.h)
set(AUDIOPLAYBACK engine/main/audio/simple-audio/AudioPlayback.h engine/main/audio/simple-audio/AudioPlayback.cpp)
set(AUDIO ${PLAYER} ${AUDIOPLAYBACK})

set(WINDOWS engine/main/view/windows/base/window/Window.h engine/main/view/windows/base/observer/Observer.h engine/main/view/windows/base/window/Window.cpp engine/main/view/windows/base/observers/WindowCloseObserver.cpp engine/main/view/windows/base/observers/WindowCloseObserver.h engine/main/view/windows/custom/PrimaryWindow/PrimaryWindow.cpp engine/main/view/windows/custom/PrimaryWindow/PrimaryWindow.h)
set(VIEWCREATE engine/main/view/create/window/WindowFactory.h engine/main/view/create/window/PrimaryWindowFactory.cpp engine/main/view/create/window/PrimaryWindowFactory.h)
set(VIEW ${WINDOWS} ${VIEWCREATE})

set(CAPABILITIES engine/main/objects/capabilities/Drawable.h)
set(OBJECTS ${CAPABILITIES})

set(LOGGER engine/utils/logger/Logger.h engine/utils/logger/BaseLogger.cpp engine/utils/logger/BaseLogger.h engine/utils/logger/formatter/Formatter.h engine/utils/logger/formatter/BaseLoggerFormatter.cpp engine/utils/logger/formatter/BaseLoggerFormatter.h)
set(WRITER engine/utils/writer/Writer.h engine/utils/writer/FileWriter.cpp engine/utils/writer/FileWriter.h engine/utils/writer/MultiFileWriter.cpp engine/utils/writer/MultiFileWriter.h)
set(READER engine/utils/reader/Reader.h engine/utils/reader/FileReader.cpp engine/utils/reader/FileReader.h)
set(INI engine/utils/Ini/IniProcessor.h engine/utils/Ini/analyzer/Analyzer.h engine/utils/Ini/BaseIniProcessor.cpp engine/utils/Ini/BaseIniProcessor.h engine/utils/Ini/analyzer/IniAnalyzer.cpp engine/utils/Ini/analyzer/IniAnalyzer.h)
set(TRIM engine/utils/trim/trim.h)
set(UTILS ${LOGGER} ${WRITER} ${READER} ${INI} ${TRIM})

set(EXCEPTIONS engine/main/general/exceptions/RuntimeException.h engine/main/general/exceptions/Exception.cpp engine/main/general/exceptions/Exception.h engine/main/general/exceptions/LogicError.h engine/main/general/exceptions/InvalidArgument.h engine/main/general/exceptions/custom/FileCanNotBeOpened.h engine/main/general/exceptions/ExceptionCodes.h)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++${CMAKE_CXX_STANDARD} -pthread")

add_executable(Flash ${MAIN} ${ENGINE} ${AUDIO} ${VIEW} ${OBJECTS} ${UTILS} ${EXCEPTIONS})

target_link_libraries(Flash sfml-window sfml-graphics sfml-audio)
