//
// Created by roman on 29.09.2020.
//

#include "GeneratorSelector.h"
#include "../generators/effects/GravityEffectGenerator.h"
#include "../generators/effects/GravityPointEffectGenerator.h"
#include "../generators/effects/BackAudioEffectGenerator.h"
#include "../generators/mobs/MushroomGenerator.h"
#include "../generators/obstacles/DullBlockGenerator.h"
#include "../generators/obstacles/DullInvisibleBlockGenarator.h"
#include "../generators/obstacles/PlatformBlockGenerator.h"
#include "../generators/players/BasicPlayerGenerator.h"
#include "../generators/sprites/BackgroundSpriteGenerator.h"
#include "../generators/sprites/BackSpriteGenerator.h"
#include "../generators/sprites/FrontSpriteGenerator.h"
#include "../generators/text/TextGenerator.h"
#include "../generators/triggers/ExplicitPlayerSceneTriggerGenerator.h"
#include "../generators/triggers/AbscissaPlayerSceneTriggerGenerator.h"
#include "../generators/triggers/OrdinatePlayerSceneTriggerGenerator.h"
#include "../generators/triggers/PlayerAudioTriggerGenerator.h"
#include "../generators/triggers/MobsAudioTriggerGenerator.h"
#include "../generators/triggers/SinglePlayerAudioTriggerGenerator.h"
#include "../generators/triggers/SingleMobsAudioTriggerGenerator.h"
#include "../generators/triggers/PlayerDeathTriggerGenerator.h"
#include "../generators/triggers/MobsDeathTriggerGenerator.h"
#include "../generators/triggers/DeathTriggerGenerator.h"
#include "../generators/triggers/AccelerationPlayerTriggerGenerator.h"
#include "../generators/triggers/AccelerationMobsTriggerGenerator.h"
#include "../generators/triggers/AccelerationTriggerGenerator.h"

Generate::GeneratorSelector::GeneratorSelector(Generate::Pools::SourcePool &pool, View::StateChangeable *context)
        : m_pool(pool), m_context(context) {}

Generate::Generator *
Generate::GeneratorSelector::select(const std::string &alias) const noexcept {
    using namespace Generate;
    //effects
    if (alias == "GravityEffect")
        return new GravityEffectGenerator(m_pool);
    if (alias == "GravityPointEffect")
        return new GravityPointEffectGenerator(m_pool);
    if (alias == "BackAudioEffect")
        return new BackAudioEffectGenerator(m_pool);

    //mobs
    if (alias == "Mushroom")
        return new MushroomGenerator(m_pool);

    //obstacles
    if (alias == "DullBlock")
        return new DullBlockGenerator(m_pool);
    if (alias == "DullInvisibleBlock")
        return new DullInvisibleBlockGenarator(m_pool);
    if (alias == "PlatformBlock")
        return new PlatformBlockGenerator(m_pool);

    //players
    if (alias == "BasicPlayer")
        return new BasicPlayerGenerator(m_pool);

    //sprites
    if (alias == "BackGroundSprite")
        return new BackgroundSpriteGenerator(m_pool);
    if (alias == "BackSprite")
        return new BackSpriteGenerator(m_pool);
    if (alias == "FrontSprite")
        return new FrontSpriteGenerator(m_pool);

    //text
    if (alias == "Text")
        return new TextGenerator(m_pool);

    //triggers
    if (alias == "ExplicitPlayerSceneTrigger")
        return new ExplicitPlayerSceneTriggerGenerator(m_pool, m_context);
    if (alias == "AbscissaPlayerSceneTrigger")
        return new AbscissaPlayerSceneTriggerGenerator(m_pool, m_context);
    if (alias == "OrdinatePlayerSceneTrigger")
        return new OrdinatePlayerSceneTriggerGenerator(m_pool, m_context);
    if (alias == "PlayerAudioTrigger")
        return new PlayerAudioTriggerGenerator(m_pool);
    if (alias == "MobsAudioTrigger")
        return new MobsAudioTriggerGenerator(m_pool);
    if (alias == "SinglePlayerAudioTrigger")
        return new SinglePlayerAudioTriggerGenerator(m_pool);
    if (alias == "SingleMobsAudioTrigger")
        return new SingleMobsAudioTriggerGenerator(m_pool);
    if (alias == "PlayerDeathTrigger")
        return new PlayerDeathTriggerGenerator(m_pool);
    if (alias == "MobsDeathTrigger")
        return new MobsDeathTriggerGenerator(m_pool);
    if (alias == "DeathTrigger")
        return new DeathTriggerGenerator(m_pool);
    if (alias == "AccelerationPlayerTrigger")
        return new AccelerationPlayerTriggerGenerator(m_pool);
    if (alias == "AccelerationMobsTrigger")
        return new AccelerationMobsTriggerGenerator(m_pool);
    if (alias == "AccelerationTrigger")
        return new AccelerationTriggerGenerator(m_pool);

    return nullptr;
}