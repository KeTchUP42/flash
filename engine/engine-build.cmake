#----------------------------------------------------------------------------
# Cmake file with all include source files.
#
# Main variables are - ENTRY_POINT, DATA, OBJECTS, SUPPORT, VIEW, UTILS.
# Global engine source files variable - ENGINE.
#----------------------------------------------------------------------------
set(SETUP engine/init/setup/EngineConfigurator.cpp)
set(ENTRY_POINT ${SETUP} engine/init/Engine.cpp)

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
set(WINDOW_VIEW ${WINDOWS} ${OBSERVERS} ${SCREEN})
set(VIEW_CREATE engine/main/view/create/WindowFactory.cpp)

set(VIEW ${WINDOW_VIEW} ${VIEW_CREATE})

set(ELEMENTARY engine/main/objects/auxiliary/components/elementary/size/Size.cpp engine/main/objects/auxiliary/components/elementary/speed/Speed.cpp engine/main/objects/auxiliary/components/elementary/point/Point.cpp engine/main/objects/auxiliary/components/elementary/area/Area.cpp)
set(MATH_HELP engine/main/objects/auxiliary/components/math/RotatingMath.cpp)
set(SPRITES engine/main/objects/auxiliary/components/sprite/common-base/ISprite.cpp engine/main/objects/auxiliary/components/sprite/primitive/ISpriteBox.cpp engine/main/objects/auxiliary/components/sprite/primitive/SpriteBox.cpp engine/main/objects/auxiliary/components/sprite/composite/ICompositeSprite.cpp engine/main/objects/auxiliary/components/sprite/composite/CompositeSprite.cpp)
set(TEXT engine/main/objects/auxiliary/components/text/Text.cpp)
set(COMPONENTS ${ELEMENTARY} ${MATH_HELP} ${SPRITES} ${TEXT})
set(COMPUTATIONS engine/main/objects/auxiliary/computations/CoordinatesComputations.cpp)
set(AUXILIARY ${COMPONENTS} ${COMPUTATIONS})

set(EFFECTS_GENERATORS engine/main/objects/creation/scene/generators/effects/BackAudioEffectGenerator.cpp engine/main/objects/creation/scene/generators/effects/GravityEffectGenerator.cpp engine/main/objects/creation/scene/generators/effects/GravityPointEffectGenerator.cpp)
set(MOBS_GENERATORS engine/main/objects/creation/scene/generators/mobs/MushroomGenerator.cpp)
set(OBSTACLES_GENERATORS engine/main/objects/creation/scene/generators/obstacles/DullBlockGenerator.cpp engine/main/objects/creation/scene/generators/obstacles/DullInvisibleBlockGenarator.cpp engine/main/objects/creation/scene/generators/obstacles/PlatformBlockGenerator.cpp)
set(PLAYERS_GENERATORS engine/main/objects/creation/scene/generators/players/BasicPlayerGenerator.cpp)
set(SPRITES_GENERATORS engine/main/objects/creation/scene/generators/sprites/BackgroundSpriteGenerator.cpp engine/main/objects/creation/scene/generators/sprites/BackSpriteGenerator.cpp engine/main/objects/creation/scene/generators/sprites/FrontSpriteGenerator.cpp)
set(TEXT_GENERATORS engine/main/objects/creation/scene/generators/text/TextGenerator.cpp)
set(TRIGGERS_GENERATORS engine/main/objects/creation/scene/generators/triggers/DeathZoneGenerator.cpp engine/main/objects/creation/scene/generators/triggers/GravityZoneGenerator.cpp engine/main/objects/creation/scene/generators/triggers/GravityMobsZoneGenerator.cpp engine/main/objects/creation/scene/generators/triggers/GravityPlayerZoneGenerator.cpp engine/main/objects/creation/scene/generators/triggers/MobsDeathZoneGenerator.cpp engine/main/objects/creation/scene/generators/triggers/PlayerDeathZoneGenerator.cpp engine/main/objects/creation/scene/generators/triggers/SingleMobsAudioTriggerGenerator.cpp engine/main/objects/creation/scene/generators/triggers/SinglePlayerAudioTriggerGenerator.cpp engine/main/objects/creation/scene/generators/triggers/MobsAudioTriggerGenerator.cpp engine/main/objects/creation/scene/generators/triggers/PlayerAudioTriggerGenerator.cpp engine/main/objects/creation/scene/generators/triggers/ExplicitPlayerSceneTriggerGenerator.cpp engine/main/objects/creation/scene/generators/triggers/AbscissaPlayerSceneTriggerGenerator.cpp engine/main/objects/creation/scene/generators/triggers/OrdinatePlayerSceneTriggerGenerator.cpp)
set(REDUCTION engine/main/objects/creation/scene/generators/reduction/KeyMapBuilder.cpp engine/main/objects/creation/scene/generators/reduction/ElementaryReduction.cpp engine/main/objects/creation/scene/generators/reduction/PropertiesReduction.cpp engine/main/objects/creation/scene/generators/reduction/AreaReduction.cpp engine/main/objects/creation/scene/generators/reduction/CustomReduction.cpp)
set(GENERATORS ${REDUCTION} ${EFFECTS_GENERATORS} ${MOBS_GENERATORS} ${OBSTACLES_GENERATORS} ${PLAYERS_GENERATORS} ${SPRITES_GENERATORS} ${TEXT_GENERATORS} ${TRIGGERS_GENERATORS})
set(ANALYZE engine/main/objects/creation/scene/analyze/GeneratorSelector.cpp engine/main/objects/creation/scene/analyze/DirectivesAnalyzer.cpp)
set(POOLS engine/main/objects/creation/scene/pools/SourcePool.cpp engine/main/objects/creation/scene/pools/GeneratorsPool.cpp engine/main/objects/creation/scene/pools/AlgorithmsPool.cpp)
set(SCENE ${GENERATORS} ${ANALYZE} ${POOLS} engine/main/objects/creation/scene/SceneLoader.cpp)
set(GENERATION ${SCENE})

set(PLAYER_CUSTOM engine/main/objects/material/mobs/players/custom/basic/BasicPlayer.cpp)
set(PLAYER_COMMON engine/main/objects/material/mobs/players/common/base/Player.cpp)
set(PLAYER ${PLAYER_COMMON} ${PLAYER_CUSTOM})

set(MUSHROOM engine/main/objects/material/mobs/custom/mushroom/Mushroom.cpp)
set(MOBS_CUSTOM ${MUSHROOM})
set(MOBS_COMMON engine/main/objects/material/mobs/common/base/Mob.cpp)
set(MOBS ${MOBS_COMMON} ${MOBS_CUSTOM} ${PLAYER})

set(SPRITE-VISIBLE engine/main/objects/material/obstacles/blocks/sprite-visible/single/common-base/SingleSpriteBlock.cpp engine/main/objects/material/obstacles/blocks/sprite-visible/single/DullBlock.cpp engine/main/objects/material/obstacles/blocks/sprite-visible/composite/common-base/CompositeSpriteBlock.cpp engine/main/objects/material/obstacles/blocks/sprite-visible/composite/DullCompositeBlock.cpp engine/main/objects/material/obstacles/blocks/sprite-visible/single/ElasticBlock.cpp engine/main/objects/material/obstacles/blocks/sprite-visible/single/PlatformBlock.cpp)
set(INVISIBLE engine/main/objects/material/obstacles/blocks/invisible/common-base/InvisibleBlock.cpp engine/main/objects/material/obstacles/blocks/invisible/DullInvisibleBlock.cpp)
set(BLOCKS ${INVISIBLE} ${SPRITE-VISIBLE} engine/main/objects/material/obstacles/blocks/common/Block.cpp)
set(OBSTACLES_COMMON engine/main/objects/material/obstacles/common/Obstacle.cpp)
set(OBSTACLES ${BLOCKS} ${OBSTACLES_COMMON})

set(ALGORITHMS engine/main/objects/material/common/algorithms/Algorithms.cpp)
set(COLLISION_ALGORITHMS engine/main/objects/material/common/collision/algorithms/collision/CommonCollisionAlgorithms.cpp engine/main/objects/material/common/collision/algorithms/collision/StaticCollisionAlgorithms.cpp engine/main/objects/material/common/collision/algorithms/collision/MovingCollisionAlgorithms.cpp engine/main/objects/material/common/collision/algorithms/coordinates/MovingCollisionFunctions.cpp engine/main/objects/material/common/collision/algorithms/coordinates/CoordinatesCalculation.cpp)
set(COLLISION ${COLLISION_ALGORITHMS} engine/main/objects/material/common/collision/Collision.cpp engine/main/objects/material/common/collision/moving-collision/MovingCollision.cpp engine/main/objects/material/common/collision/static-collision/StaticCollision.cpp)
set(MATERIAL_COMMON ${ALGORITHMS} ${COLLISION} engine/main/objects/material/common/MaterialObject.cpp)
set(MATERIAL ${MOBS} ${OBSTACLES} ${MATERIAL_COMMON})

set(AUDIO_EFFECTS engine/main/objects/static/effects/audio/back/BackAudioEffect.cpp)
set(GRAVITY_EFFECTS engine/main/objects/static/effects/gravity/GravityEffect.cpp engine/main/objects/static/effects/gravity/GravityPointEffect.cpp)
set(EFFECTS ${AUDIO_EFFECTS} ${GRAVITY_EFFECTS})

set(HANDLERS engine/main/objects/static/triggers/scene/player/handlers/ExplicitPositionPlayerHandler.cpp engine/main/objects/static/triggers/scene/player/handlers/AbscissaPositionPlayerHandler.cpp engine/main/objects/static/triggers/scene/player/handlers/OrdinatePositionPlayerHandler.cpp)
set(SCENE_TRIGGERS engine/main/objects/static/triggers/scene/player/PlayerSceneTrigger.cpp)
set(AUDIO_TRIGGERS engine/main/objects/static/triggers/audio/mobs/MobsAudioTrigger.cpp engine/main/objects/static/triggers/audio/player/PlayerAudioTrigger.cpp engine/main/objects/static/triggers/audio/mobs/SingleMobsAudioTrigger.cpp engine/main/objects/static/triggers/audio/player/SinglePlayerAudioTrigger.cpp)
set(IMPACT_TRIGGERS engine/main/objects/static/triggers/impact/mobs/ImpactMobsZone.cpp engine/main/objects/static/triggers/impact/player/ImpactPlayerZone.cpp)
set(TRIGGERS ${HANDLERS} ${SCENE_TRIGGERS} ${AUDIO_TRIGGERS} ${IMPACT_TRIGGERS} engine/main/objects/static/triggers/common/AreaTrigger.cpp)
set(STATIC ${EFFECTS} ${TRIGGERS})

set(UNIFIER engine/main/objects/unifier/common/Unifier.cpp engine/main/objects/unifier/SceneUnifier.cpp)

set(OBJECTS ${AUXILIARY} ${GENERATION} ${MATERIAL} ${STATIC} ${UNIFIER})

set(LOGGER engine/utils/logger/Logger.cpp engine/utils/logger/formatter/LoggerFormatter.cpp)
set(WRITER engine/utils/writer/FileWriter.cpp engine/utils/writer/MultiFileWriter.cpp)
set(READER engine/utils/reader/FileReader.cpp)
set(INI engine/utils/Ini/IniProcessor.cpp engine/utils/Ini/analyzer/IniAnalyzer.cpp engine/utils/Ini/creator/IniCreator.cpp)
set(MATH engine/utils/math/algorithms.cpp)
set(UTILS ${LOGGER} ${WRITER} ${READER} ${INI} ${MATH})

set(EXCEPTIONS engine/main/support/exceptions/Exception.cpp)
set(SUPPORT ${EXCEPTIONS})

set(ENGINE ${ENTRY_POINT} ${DATA} ${OBJECTS} ${SUPPORT} ${VIEW} ${UTILS})