#----------------------------------------------------------------------------
# Cmake file with all include source files.
#
# Main variables are - ENTRY_POINT, DATA, OBJECTS, OTHER, VIEW, SETUP, UTILS.
# Global engine source files variable - ENGINE.
#----------------------------------------------------------------------------
set(ENTRY_POINT engine/init/Engine.cpp)

set(AUDIOPLAYBACK engine/main/data/audio/simple-audio/AudioPlayback.cpp)
set(AUDIO ${AUDIOPLAYBACK})

set(AUDIO_MANAGER engine/main/data/manager/audio-manager/MusicManager.cpp)
set(CONFIG_MANAGER engine/main/data/manager/config-manager/IniConfigManager.cpp)
set(FONT_MANAGER engine/main/data/manager/font-manager/BasicFontManager.cpp)
set(LOG_MANAGER engine/main/data/manager/log-manager/BasicLogManager.cpp)
set(TEXTURE_MANAGER engine/main/data/manager/texture-manager/BasicTextureManager.cpp)
set(DATA_MANAGER engine/main/data/manager/DataManager.cpp)
set(MANAGERS ${AUDIO_MANAGER} ${CONFIG_MANAGER} ${FONT_MANAGER} ${LOG_MANAGER} ${TEXTURE_MANAGER} ${DATA_MANAGER})
set(DATA ${AUDIO} ${MANAGERS})

set(OBSERVERS engine/main/view/windows/base/observers/WindowCloseObserver.cpp engine/main/view/windows/base/observers/WindowResizeObserver.cpp)
set(WINDOWS engine/main/view/windows/base/window/Window.cpp engine/main/view/windows/custom/PrimaryWindow/PrimaryWindow.cpp)
set(SCREEN engine/main/view/windows/screen/states/InitialScreenState.cpp engine/main/view/windows/screen/states/TransitScreenState.cpp)
set(WINDOWVIEW ${WINDOWS} ${OBSERVERS} ${SCREEN})
set(VIEWCREATE engine/main/view/create/window/PrimaryWindowFactory.cpp)

set(VIEW ${WINDOWVIEW} ${VIEWCREATE})

set(ELEMENTARY engine/main/objects/auxiliary/components/elementary/point/Point.cpp engine/main/objects/auxiliary/components/elementary/area/Area.cpp)
set(SPRITES engine/main/objects/auxiliary/components/sprite/common-base/ISprite.cpp engine/main/objects/auxiliary/components/sprite/primitive/SpriteBox.cpp engine/main/objects/auxiliary/components/sprite/composite/CompositeSprite.cpp)
set(COMPONENTS ${ELEMENTARY} ${SPRITES})
set(AUXILIARY ${COMPONENTS})

set(LEVEL engine/main/objects/generating/level/StartLevelFactory.cpp)
set(GENERATING ${LEVEL})

set(MONSTERS_COMMON)
set(MONSTERS ${MONSTERS_COMMON} engine/main/objects/material/mobs/monsters/common-base/Monster.cpp engine/main/objects/material/mobs/monsters/custom/mushroom/Mushroom.cpp)

set(PLAYER_COMMON)
set(PLAYER ${PLAYER_COMMON} engine/main/objects/material/mobs/player/common-base/Player.cpp engine/main/objects/material/mobs/player/custom/BasicPlayer.cpp)
set(MOBS_COMMON)
set(MOBS ${MONSTERS} ${PLAYER} ${MOBS_COMMON})

set(BLOCKS engine/main/objects/material/obstacles/blocks/single/common-base/SingleSpriteBlock.cpp engine/main/objects/material/obstacles/blocks/single/DullBlock.cpp engine/main/objects/material/obstacles/blocks/composite/common-base/CompositeSpriteBlock.cpp engine/main/objects/material/obstacles/blocks/composite/DullCompositeBlock.cpp engine/main/objects/material/obstacles/blocks/single/ElasticBlock.cpp)
set(OBSTACLES_COMMON)
set(OBSTACLES ${BLOCKS} ${OBSTACLES_COMMON})

set(COLLISION engine/main/objects/material/common/collision/Collision.cpp engine/main/objects/material/common/collision/coordinates/CoordinatesCalculation.cpp engine/main/objects/material/common/collision/moving-collision/MovingCollision.cpp engine/main/objects/material/common/collision/moving-collision/ObstacleCollision.cpp engine/main/objects/material/common/collision/moving-collision/PlayerCollision.cpp engine/main/objects/material/common/collision/moving-collision/MonsterCollision.cpp engine/main/objects/material/common/collision/static-collision/StaticObstacleCollision.cpp engine/main/objects/material/common/collision/static-collision/StaticMonsterCollision.cpp engine/main/objects/material/common/collision/static-collision/StaticPlayerCollision.cpp engine/main/objects/material/common/collision/static-collision/additionally/ExtremeCoordinates.cpp)
set(MATERIAL_COMMON ${COLLISION})
set(MATERIAL ${MOBS} ${OBSTACLES} ${MATERIAL_COMMON})

set(EFFECTS engine/main/objects/static/effects/GravityEffect.cpp)
set(TRIGGERS engine/main/objects/static/triggers/area/PlainLevelTrigger.cpp)
set(STATIC ${EFFECTS} ${TRIGGERS})

set(UNIFIER engine/main/objects/unifier/common-base/Unifier.cpp engine/main/objects/unifier/GeneralUnifier.cpp)

set(OBJECTS ${AUXILIARY} ${GENERATING} ${MATERIAL} ${STATIC} ${UNIFIER})

set(SETUP engine/setup/EngineConfigurator.cpp)

set(LOGGER engine/utils/logger/BasicLogger.cpp engine/utils/logger/formatter/BaseLoggerFormatter.cpp)
set(WRITER engine/utils/writer/FileWriter.cpp engine/utils/writer/MultiFileWriter.cpp)
set(READER engine/utils/reader/FileReader.cpp)
set(INI engine/utils/Ini/BasicIniProcessor.cpp engine/utils/Ini/analyzer/IniAnalyzer.cpp)
set(OTHER engine/utils/other/Calculations.cpp)
set(UTILS ${LOGGER} ${WRITER} ${READER} ${INI} ${OTHER})

set(EXCEPTIONS engine/main/other/exceptions/Exception.cpp)
set(OTHER ${EXCEPTIONS})

set(ENGINE ${ENTRY_POINT} ${DATA} ${OBJECTS} ${OTHER} ${VIEW} ${SETUP} ${UTILS})