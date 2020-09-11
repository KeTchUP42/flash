cmake_minimum_required(VERSION 3.16)
project(Flash)

set(CMAKE_CXX_STANDARD 11)

set(SFML_DIR ./lib/SFML-2.5.1/lib/cmake/SFML)

find_package(SFML 2.5.1 COMPONENTS window graphics audio)

set(MAIN init/main.cpp)
set(ENGINE engine/init/Engine.cpp engine/init/Engine.h)

set(PLAYER engine/main/data/audio/player/AudioPlayer.h engine/main/data/audio/player/MusicPlayer.cpp engine/main/data/audio/player/MusicPlayer.h engine/main/data/audio/player/SoundPlayer.cpp engine/main/data/audio/player/SoundPlayer.h)
set(AUDIOPLAYBACK engine/main/data/audio/simple-audio/AudioPlayback.h engine/main/data/audio/simple-audio/AudioPlayback.cpp)
set(AUDIO ${PLAYER} ${AUDIOPLAYBACK})

set(AUDIOMANAGER engine/main/data/manager/audio-manager/AudioManager.h engine/main/data/manager/audio-manager/MusicManager.cpp engine/main/data/manager/audio-manager/MusicManager.h)
set(CONFIGMANAGER engine/main/data/manager/config-manager/ConfigManager.h engine/main/data/manager/config-manager/IniConfigManager.cpp engine/main/data/manager/config-manager/IniConfigManager.h)
set(FONTMANAGER engine/main/data/manager/font-manager/FontManager.h engine/main/data/manager/font-manager/BaseFontManager.cpp engine/main/data/manager/font-manager/BaseFontManager.h)
set(LOGMANAGER engine/main/data/manager/log-manager/BaseLogManager.cpp engine/main/data/manager/log-manager/BaseLogManager.h)
set(TEXTUREMANAGER engine/main/data/manager/texture-manager/TextureManager.h engine/main/data/manager/texture-manager/BaseTextureManager.cpp engine/main/data/manager/texture-manager/BaseTextureManager.h)
set(DATAMANAGER engine/main/data/manager/DataManager.h engine/main/data/manager/StandardDataManager.cpp engine/main/data/manager/StandardDataManager.h)
set(MANAGERS ${AUDIOMANAGER} ${CONFIGMANAGER} ${FONTMANAGER} ${LOGMANAGER} ${TEXTUREMANAGER} ${DATAMANAGER})
set(DATA ${AUDIO} ${MANAGERS})

set(OBSERVERS engine/main/view/windows/base/observer/Observer.h engine/main/view/windows/base/observers/WindowCloseObserver.cpp engine/main/view/windows/base/observers/WindowCloseObserver.h engine/main/view/windows/base/observers/WindowResizeObserver.cpp engine/main/view/windows/base/observers/WindowResizeObserver.h)
set(WINDOWS engine/main/view/windows/base/window/Window.h engine/main/view/windows/base/window/Window.cpp engine/main/view/windows/custom/PrimaryWindow/PrimaryWindow.cpp engine/main/view/windows/custom/PrimaryWindow/PrimaryWindow.h)
set(SCREEN engine/main/view/windows/screen/context-abilities/StateChangeable.h engine/main/view/windows/screen/states/base/ScreenState.h engine/main/view/windows/screen/states/base/ScreenState.cpp engine/main/view/windows/screen/states/BaseScreenState.cpp engine/main/view/windows/screen/states/BaseScreenState.h)
set(WINDOWVIEW ${WINDOWS} ${OBSERVERS} ${SCREEN})
set(VIEWCREATE engine/main/view/create/window/WindowFactory.h engine/main/view/create/window/PrimaryWindowFactory.cpp engine/main/view/create/window/PrimaryWindowFactory.h)

set(VIEW ${WINDOWVIEW} ${VIEWCREATE})

set(POSSIBILITIES engine/main/objects/auxiliary/possibilities/Drawable.h engine/main/objects/auxiliary/possibilities/Movable.h engine/main/objects/auxiliary/possibilities/CollisionProne.h engine/main/objects/auxiliary/possibilities/Rotatable.h engine/main/objects/auxiliary/possibilities/SelfMovable.h engine/main/objects/auxiliary/possibilities/SelfActionable.h)
set(ELEMENTARY engine/main/objects/auxiliary/components/elementary/point/Point.h engine/main/objects/auxiliary/components/elementary/point/Point.cpp engine/main/objects/auxiliary/components/elementary/Size.h engine/main/objects/auxiliary/components/elementary/Speed.h)
set(SPRITE engine/main/objects/auxiliary/components/sprite/common/box/SpriteBox.cpp engine/main/objects/auxiliary/components/sprite/common/box/SpriteBox.h engine/main/objects/auxiliary/components/sprite/common/base/ISprite.h engine/main/objects/auxiliary/components/sprite/composite/ICompositeSprite.h engine/main/objects/auxiliary/components/sprite/composite/CompositeSprite.cpp engine/main/objects/auxiliary/components/sprite/composite/CompositeSprite.h engine/main/objects/auxiliary/components/sprite/common/box/ISpriteBox.h)
set(COMPONENTS ${ELEMENTARY} ${SPRITE})
set(AUXILIARY ${POSSIBILITIES} ${COMPONENTS})

set(BACK engine/main/objects/generating/components/background/BackGroundSpriteBoxFactory.h engine/main/objects/generating/components/background/PrimaryBackGroundFactory.cpp engine/main/objects/generating/components/background/PrimaryBackGroundFactory.h)
set(SPRITES engine/main/objects/generating/components/sprites/SpriteFactory.h engine/main/objects/generating/components/sprites/StoneWallSpriteFactory.cpp engine/main/objects/generating/components/sprites/StoneWallSpriteFactory.h)
set(COMPONENTS ${BACK} ${SPRITES})
set(LEVEL engine/main/objects/generating/level/LevelUnifierFactory.h engine/main/objects/generating/level/StartLevelFactory.cpp engine/main/objects/generating/level/StartLevelFactory.h)
set(GENERATING ${COMPONENTS} ${LEVEL})

set(PLAYER engine/main/objects/mobs/player/base/Player.h engine/main/objects/mobs/player/base/Player.cpp engine/main/objects/mobs/player/control/KeyAlias.h engine/main/objects/mobs/player/custom/CommonPlayer.cpp engine/main/objects/mobs/player/custom/CommonPlayer.h)
set(SHARED engine/main/objects/mobs/shared/Mob.h)
set(MOBS ${PLAYER} ${SHARED})

set(UNIFIER engine/main/objects/unifier/base/Unifier.h engine/main/objects/unifier/base/Unifier.cpp engine/main/objects/unifier/CommonUnifier.cpp engine/main/objects/unifier/CommonUnifier.h)

set(EFFECTS engine/main/objects/static/effects/Effect.h engine/main/objects/static/effects/GravityEffect.cpp engine/main/objects/static/effects/GravityEffect.h)
set(STATIC ${EFFECTS})

set(OBJECTS ${AUXILIARY} ${GENERATING} ${MOBS} ${UNIFIER} ${STATIC})

set(SETUP engine/setup/Configurator.h engine/setup/EngineConfigurator.cpp engine/setup/EngineConfigurator.h)

set(LOGGER engine/utils/logger/Logger.h engine/utils/logger/BaseLogger.cpp engine/utils/logger/BaseLogger.h engine/utils/logger/formatter/Formatter.h engine/utils/logger/formatter/BaseLoggerFormatter.cpp engine/utils/logger/formatter/BaseLoggerFormatter.h)
set(WRITER engine/utils/writer/Writer.h engine/utils/writer/FileWriter.cpp engine/utils/writer/FileWriter.h engine/utils/writer/MultiFileWriter.cpp engine/utils/writer/MultiFileWriter.h)
set(READER engine/utils/reader/Reader.h engine/utils/reader/FileReader.cpp engine/utils/reader/FileReader.h)
set(INI engine/utils/Ini/IniProcessor.h engine/utils/Ini/analyzer/Analyzer.h engine/utils/Ini/BaseIniProcessor.cpp engine/utils/Ini/BaseIniProcessor.h engine/utils/Ini/analyzer/IniAnalyzer.cpp engine/utils/Ini/analyzer/IniAnalyzer.h)
set(TRIM engine/utils/trim/trim.h)
set(UTILS ${LOGGER} ${WRITER} ${READER} ${INI} ${TRIM})

set(EXCEPTIONS engine/main/general/exceptions/RuntimeException.h engine/main/general/exceptions/Exception.cpp engine/main/general/exceptions/Exception.h engine/main/general/exceptions/LogicError.h engine/main/general/exceptions/InvalidArgument.h engine/main/general/exceptions/custom/FileCanNotBeOpened.h engine/main/general/exceptions/ExceptionCodes.h engine/main/general/exceptions/custom/AudioFileCanNotBeOpened.h engine/main/general/exceptions/custom/TextureCanNotBeLoaded.h engine/main/general/exceptions/custom/FontCanNotBeLoaded.h)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++${CMAKE_CXX_STANDARD} -pthread")

add_executable(Flash ${MAIN} ${ENGINE} ${DATA} ${VIEW} ${OBJECTS} ${SETUP} ${UTILS} ${EXCEPTIONS})

target_link_libraries(Flash sfml-window sfml-graphics sfml-audio)
