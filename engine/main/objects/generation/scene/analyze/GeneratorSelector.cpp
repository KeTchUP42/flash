//
// Created by roman on 29.09.2020.
//

#include "GeneratorSelector.h"
#include "../generators/effects/GravityEffectGenerator.h"
#include "../generators/monsters/MushroomGenerator.h"
#include "../generators/obstacles/DullBlockGenerator.h"
#include "../generators/obstacles/DullInvisibleBlockGenarator.h"
#include "../generators/players/BasicPlayerGenerator.h"
#include "../generators/sprites/BackgroundSpriteGenerator.h"
#include "../generators/sprites/BackSpriteGenerator.h"
#include "../generators/sprites/FrontSpriteGenerator.h"
#include "../generators/triggers/ExplicitPlayerSceneTriggerGenerator.h"
#include "../generators/triggers/AbscissaPlayerSceneTriggerGenerator.h"
#include "../generators/triggers/OrdinatePlayerSceneTriggerGenerator.h"


Generate::GeneratorSelector::GeneratorSelector(Generate::Pools::SourcePool &pool, Screen::StateChangeable *context)
        : m_pool(pool), m_context(context) {}


Generate::Generator *
Generate::GeneratorSelector::select(const std::string &alias) const noexcept {
    using namespace Generate;
    //effects
    if (alias == "GravityEffect")
        return new GravityEffectGenerator(m_pool);

    //monsters
    if (alias == "Mushroom")
        return new MushroomGenerator(m_pool);

    //obstacles
    if (alias == "DullBlock")
        return new DullBlockGenerator(m_pool);
    if (alias == "DullInvisibleBlock")
        return new DullInvisibleBlockGenarator(m_pool);

    //players
    if (alias == "BasicPlayer")
        return new BasicPlayerGenerator(m_pool);

    //sprites
    if (alias == "BackgroundSprite")
        return new BackgroundSpriteGenerator(m_pool);
    if (alias == "BackSprite")
        return new BackSpriteGenerator(m_pool);
    if (alias == "FrontSprite")
        return new FrontSpriteGenerator(m_pool);

    //triggers
    if (alias == "ExplicitPlayerSceneTrigger")
        return new ExplicitPlayerSceneTriggerGenerator(m_pool, m_context);
    if (alias == "AbscissaPlayerSceneTrigger")
        return new AbscissaPlayerSceneTriggerGenerator(m_pool, m_context);
    if (alias == "OrdinatePlayerSceneTrigger")
        return new OrdinatePlayerSceneTriggerGenerator(m_pool, m_context);

    return nullptr;
}