#----------------------------------------------------------------------------
# Cmake file with all include source files.
#
# Main variables are - ENTRY_POINT, DATA, OBJECTS, OTHER, VIEW, SETUP, UTILS.
# Global engine source files variable - ENGINE.
#----------------------------------------------------------------------------
set(ENTRY_POINT engine/init/Engine.cpp)

set(AUDIOPLAYBACK engine/main/data/audio/simple-audio/AudioPlayback.cpp)
set(AUDIO ${AUDIOPLAYBACK})

set(AUDIO_MANAGER engine/main/data/manager/audio-manager/AudioManager.cpp)
set(CONFIG_MANAGER engine/main/data/manager/config-manager/ConfigManager.cpp)
set(FONT_MANAGER engine/main/data/manager/font-manager/FontManager.cpp)
set(LOG_MANAGER engine/main/data/manager/log-manager/LogManager.cpp)
set(SCENE_MANAGER engine/main/data/manager/scene-manager/SceneManager.cpp)
set(TEXTURE_MANAGER engine/main/data/manager/texture-manager/TextureManager.cpp)
set(DATA_MANAGER engine/main/data/manager/DataManager.cpp)
set(MANAGERS ${AUDIO_MANAGER} ${CONFIG_MANAGER} ${FONT_MANAGER} ${LOG_MANAGER} ${SCENE_MANAGER} ${TEXTURE_MANAGER} ${DATA_MANAGER})
set(DATA ${AUDIO} ${MANAGERS})

set(OBSERVERS engine/main/view/windows/base/observers/WindowCloseObserver.cpp engine/main/view/windows/base/observers/WindowResizeObserver.cpp)
set(WINDOWS engine/main/view/windows/base/window/Window.cpp engine/main/view/windows/custom/primary/PrimaryWindow.cpp)
set(SCREEN engine/main/view/windows/screen/states/InitialScreenState.cpp engine/main/view/windows/screen/states/TransitScreenState.cpp)
set(WINDOWVIEW ${WINDOWS} ${OBSERVERS} ${SCREEN})
set(VIEWCREATE engine/main/view/create/WindowFactory.cpp)

set(VIEW ${WINDOWVIEW} ${VIEWCREATE})

set(ELEMENTARY engine/main/objects/auxiliary/components/elementary/point/Point.cpp engine/main/objects/auxiliary/components/elementary/area/Area.cpp)
set(SPRITES engine/main/objects/auxiliary/components/sprite/common-base/ISprite.cpp engine/main/objects/auxiliary/components/sprite/primitive/SpriteBox.cpp engine/main/objects/auxiliary/components/sprite/composite/CompositeSprite.cpp)
set(TEXT engine/main/objects/auxiliary/components/text/Text.cpp)
set(COMPONENTS ${ELEMENTARY} ${SPRITES} ${TEXT})
set(AUXILIARY ${COMPONENTS})

set(EFFECTS_GENERATORS engine/main/objects/generation/scene/generators/effects/GravityEffectGenerator.cpp engine/main/objects/generation/scene/generators/effects/GravityPointEffectGenerator.cpp)
set(MONSTERS_GENERATORS engine/main/objects/generation/scene/generators/monsters/MushroomGenerator.cpp)
set(OBSTACLES_GENERATORS engine/main/objects/generation/scene/generators/obstacles/DullBlockGenerator.cpp engine/main/objects/generation/scene/generators/obstacles/DullInvisibleBlockGenarator.cpp engine/main/objects/generation/scene/generators/obstacles/PlatformBlockGenerator.cpp)
set(PLAYERS_GENERATORS engine/main/objects/generation/scene/generators/players/BasicPlayerGenerator.cpp)
set(SPRITES_GENERATORS engine/main/objects/generation/scene/generators/sprites/BackgroundSpriteGenerator.cpp engine/main/objects/generation/scene/generators/sprites/BackSpriteGenerator.cpp engine/main/objects/generation/scene/generators/sprites/FrontSpriteGenerator.cpp)
set(TEXT_GENERATORS engine/main/objects/generation/scene/generators/text/TextGenerator.cpp)
set(TRIGGERS_GENERATORS engine/main/objects/generation/scene/generators/triggers/ExplicitPlayerSceneTriggerGenerator.cpp engine/main/objects/generation/scene/generators/triggers/AbscissaPlayerSceneTriggerGenerator.cpp engine/main/objects/generation/scene/generators/triggers/OrdinatePlayerSceneTriggerGenerator.cpp)
set(GENERATORS ${EFFECTS_GENERATORS} ${MONSTERS_GENERATORS} ${OBSTACLES_GENERATORS} ${PLAYERS_GENERATORS} ${SPRITES_GENERATORS} ${TRIGGERS_GENERATORS})
set(ANALYZE engine/main/objects/generation/scene/analyze/GeneratorSelector.cpp engine/main/objects/generation/scene/analyze/BlockAnalyzer.cpp)
set(POOLS engine/main/objects/generation/scene/pools/SourcePool.cpp engine/main/objects/generation/scene/pools/GeneratorsPool.cpp engine/main/objects/generation/scene/pools/AlgorithmsPool.cpp)
set(SCENE ${GENERATORS} ${ANALYZE} ${POOLS} engine/main/objects/generation/scene/SceneGenerator.cpp)
set(GENERATION ${SCENE})

set(MUSHROOM engine/main/objects/material/mobs/monsters/custom/mushroom/Mushroom.cpp engine/main/objects/material/mobs/monsters/custom/mushroom/mind/MushroomMind.cpp)
set(MONSTERS_COMMON)
set(MONSTERS ${MONSTERS_COMMON} ${MUSHROOM} engine/main/objects/material/mobs/monsters/common/base/Monster.cpp)

set(PLAYER_COMMON)
set(PLAYER ${PLAYER_COMMON} engine/main/objects/material/mobs/player/common/base/Player.cpp engine/main/objects/material/mobs/player/custom/basic/BasicPlayer.cpp)
set(MOBS_COMMON)
set(MOBS ${MONSTERS} ${PLAYER} ${MOBS_COMMON})

set(SPRITE-VISIBLE engine/main/objects/material/obstacles/blocks/sprite-visible/single/common-base/SingleSpriteBlock.cpp engine/main/objects/material/obstacles/blocks/sprite-visible/single/DullBlock.cpp engine/main/objects/material/obstacles/blocks/sprite-visible/composite/common-base/CompositeSpriteBlock.cpp engine/main/objects/material/obstacles/blocks/sprite-visible/composite/DullCompositeBlock.cpp engine/main/objects/material/obstacles/blocks/sprite-visible/single/ElasticBlock.cpp engine/main/objects/material/obstacles/blocks/sprite-visible/single/PlatformBlock.cpp)
set(INVISIBLE engine/main/objects/material/obstacles/blocks/invisible/common-base/InvisibleBlock.cpp engine/main/objects/material/obstacles/blocks/invisible/DullInvisibleBlock.cpp)
set(BLOCKS ${INVISIBLE} ${SPRITE-VISIBLE})
set(OBSTACLES_COMMON)
set(OBSTACLES ${BLOCKS} ${OBSTACLES_COMMON})

set(ALGORITHMS engine/main/objects/material/common/algorithms/Algorithms.cpp)
set(COLLISION_ALGORITHMS engine/main/objects/material/common/collision/algorithms/collision/StaticCollisionAlgorithms.cpp engine/main/objects/material/common/collision/algorithms/collision/MovingCollisionAlgorithms.cpp engine/main/objects/material/common/collision/algorithms/coordinates/CoordinatesCalculation.cpp engine/main/objects/material/common/collision/algorithms/coordinates/ExtremeCoordinates.cpp)
set(COLLISION ${COLLISION_ALGORITHMS} engine/main/objects/material/common/collision/Collision.cpp engine/main/objects/material/common/collision/moving-collision/MovingCollision.cpp engine/main/objects/material/common/collision/static-collision/StaticCollision.cpp)
set(MATERIAL_COMMON ${ALGORITHMS} ${COLLISION} engine/main/objects/material/common/MaterialObject.cpp)
set(MATERIAL ${MOBS} ${OBSTACLES} ${MATERIAL_COMMON})

set(EFFECTS engine/main/objects/static/effects/GravityEffect.cpp engine/main/objects/static/effects/GravityPointEffect.cpp)

set(HANDLERS engine/main/objects/static/triggers/scene/player/handlers/ExplicitPositionPlayerHandler.cpp engine/main/objects/static/triggers/scene/player/handlers/AbscissaPositionPlayerHandler.cpp engine/main/objects/static/triggers/scene/player/handlers/OrdinatePositionPlayerHandler.cpp)
set(TRIGGERS engine/main/objects/static/triggers/common/AreaTrigger.cpp ${HANDLERS} engine/main/objects/static/triggers/scene/player/PlayerSceneTrigger.cpp)
set(STATIC ${EFFECTS} ${TRIGGERS})

set(UNIFIER engine/main/objects/unifier/common/Unifier.cpp engine/main/objects/unifier/GeneralUnifier.cpp)

set(OBJECTS ${AUXILIARY} ${GENERATION} ${MATERIAL} ${STATIC} ${UNIFIER})

set(SETUP engine/setup/EngineConfigurator.cpp)

set(LOGGER engine/utils/logger/BasicLogger.cpp engine/utils/logger/formatter/LoggerFormatter.cpp)
set(WRITER engine/utils/writer/FileWriter.cpp engine/utils/writer/MultiFileWriter.cpp)
set(READER engine/utils/reader/FileReader.cpp)
set(INI engine/utils/Ini/BasicIniProcessor.cpp engine/utils/Ini/analyzer/IniAnalyzer.cpp)
set(MATH engine/utils/math/RectangleMath.cpp engine/utils/math/algorithms.cpp)
set(UTILS ${LOGGER} ${WRITER} ${READER} ${INI} ${MATH})

set(EXCEPTIONS engine/main/other/exceptions/Exception.cpp)
set(OTHER ${EXCEPTIONS})

set(ENGINE ${ENTRY_POINT} ${DATA} ${OBJECTS} ${OTHER} ${VIEW} ${SETUP} ${UTILS})